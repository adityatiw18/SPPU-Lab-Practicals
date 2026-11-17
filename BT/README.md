# Blockchain Technology Practicals

## C1: Bank Account Smart Contract

### Aim
To write and deploy a bank account smart contract on an Ethereum test
network supporting deposit, withdrawal, and balance display.

### Technology Used
- Solidity
- Remix IDE
- MetaMask
- Ethereum Sepolia Test Network

### Contract Features
1. Deposit ETH into the smart contract.
2. Withdraw ETH from the caller's deposited balance.
3. Display the caller's current balance.
4. Use a mapping to maintain individual user balances.

### How to Compile and Deploy
1. Open https://remix.ethereum.org/
2. Create or open BankAccount.sol.
3. Paste the contract code.
4. Compile using Solidity compiler version 0.8.20 or compatible.
5. Select Browser Extension as the deployment environment.
6. Connect MetaMask using the Sepolia network.
7. Deploy the contract and approve the transaction in MetaMask.

### Testing
- Deposit ETH by entering an amount in the VALUE field and selecting Ether.
- Call getBalance() to check the deposited balance.
- Call withdraw() with the amount in Wei.
- Call getBalance() again to verify the updated balance.

### Gas and Transaction Fee
Deployment, deposit, and withdrawal require gas.
A normal read-only getBalance() call does not require a user-paid transaction fee.

1 ETH = 10^18 Wei