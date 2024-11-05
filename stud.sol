// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract studentData{
    struct Student{
        string name;
        uint256 age;
        uint256 roll;
    }



    Student[] public  students;


    event studentAdded(string message);


    function addStudent(string memory _name,uint256 _age,uint256 _roll) public {
        students.push(Student(_name,_age,_roll));
        emit studentAdded("new student added");
    }


    function getStudentDataByIndex(uint256 index) public  view returns(string memory,uint256,uint256){
        require(index<students.length ," index not exists");
        Student memory student=students[index];

        return (student.name,student.age,student.roll);
    }


    function getNumberOfStudents()public  view returns (uint){
        return students.length;
    }


}