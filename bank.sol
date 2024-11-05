
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract BankAccount {
    // Mapping to store balances of each customer
    mapping(address => uint256) private balances;

    // Event to log deposits
    event Deposited(address indexed customer, uint256 amount);
    
    // Event to log withdrawals
    event Withdrawn(address indexed customer, uint256 amount);

    // Function to deposit money
    function deposit() external payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        
        // Update the balance of the customer
        balances[msg.sender] += msg.value;
        
        // Emit deposit event
        emit Deposited(msg.sender, msg.value);
    }

    // Function to withdraw money
    function withdraw(uint256 amount) external    {
        require(amount > 0, "Withdrawal amount must be greater than 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");
        
        // Update the balance before transferring to prevent re-entrancy attacks
        balances[msg.sender] -= amount;

        // Transfer the specified amount to the customer
        payable(msg.sender).transfer(amount);

        // Emit withdrawal event
        emit Withdrawn(msg.sender, amount);
    }

    // Function to show balance
    function getBalance() external view returns (uint256) {
        return balances[msg.sender];
    }
}
