package Algorithm.bank;

public class Account {
    private String accountName;
    private int balance;

    public Account(String accountName, int balance) {
        this.accountName = accountName;
        this.balance = balance;
    }

    public String getAccountName() {
        return accountName;
    }

    public void setAccountName(String accountName) {
        this.accountName = accountName;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public boolean deposit(int amount){
        balance += amount;
        return true;
    }

    public boolean withdraw(int amount){
        if(balance < amount) {
            return false;
        }
        else{
            balance -= amount;
            return true;
        }
    }
}
