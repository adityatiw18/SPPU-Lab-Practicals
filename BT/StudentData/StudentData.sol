// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {

    // Structure to store student information
    struct Student {
        uint256 rollNo;
        string name;
        uint256 age;
        string course;
    }

    // Array to store multiple student records
    Student[] public students;

    // Add a new student
    function addStudent(
        uint256 _rollNo,
        string memory _name,
        uint256 _age,
        string memory _course
    ) public {
        students.push(
            Student(_rollNo, _name, _age, _course)
        );
    }

    // Get details of a student using array index
    function getStudent(uint256 index)
        public
        view
        returns (
            uint256,
            string memory,
            uint256,
            string memory
        )
    {
        require(index < students.length, "Invalid student index");

        Student memory s = students[index];

        return (s.rollNo, s.name, s.age, s.course);
    }

    // Get total number of students
    function getStudentCount() public view returns (uint256) {
        return students.length;
    }
}