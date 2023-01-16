package Algorithm.bank;

import java.util.ArrayList;
import java.util.List;

public class Customer {
    private String ssn;
    private String name;
    private List<Account> accounts;
    private int numberOfAccounts;

    public Customer(String ssn, String name) {
        this.ssn = ssn;
        this.name = name;
        this.accounts = new ArrayList<>();
        this.numberOfAccounts = 0;
    }

    public void setSsn(String ssn) {
        this.ssn = ssn;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSsn() {
        return ssn;
    }

    public String getName() {
        return name;
    }

    public List<Account> getAccounts() {
        return accounts;
    }

    public int getNumberOfAccounts() {
        return numberOfAccounts;
    }

    public void addAccount(Account account){
        if(accounts.size() >= 5){
            System.out.println("계좌를 5개 이상 만들 수 없습니다.");
            return;
        }
        accounts.add(account);
        numberOfAccounts++;
    }
}
