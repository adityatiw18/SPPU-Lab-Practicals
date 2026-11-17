// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract BankAccount {
    // Stores the balance of each user's wallet address
    mapping(address => uint256) private balances;

    // Deposit ETH into the contract
    function deposit() public payable {
        require(msg.value > 0, "Invalid deposit");
        balances[msg.sender] += msg.value;
    }

    // Withdraw ETH from the caller's balance
    function withdraw(uint256 amount) public {
        require(amount > 0, "Invalid amount");
        require(
            balances[msg.sender] >= amount,
            "Insufficient balance"
        );

        balances[msg.sender] -= amount;

        (bool success, ) = payable(msg.sender).call{value: amount}("");
        require(success, "Transfer failed");
    }

    // Display the caller's balance
    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}