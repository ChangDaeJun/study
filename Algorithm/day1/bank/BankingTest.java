package Algorithm.day1.bank;

import java.util.List;

public class BankingTest {
    public static void main(String[] args) {
        Bank bank = new Bank();

        Customer customer1 = new Customer("sie-2340-aaaeei21", "장대준");
        Customer customer2 = new Customer("sie-9988-aaaeei23", "장대호");

        bank.addCustomer(customer1);
        bank.addCustomer(customer2);

        Account account1 = new Account("장대준의 계좌1", 100_000_000);
        Account account2 = new Account("장대준의 계좌2", 100_000_000);
        Account account3 = new Account("장대준의 계좌3", 100_000_000);
        Account account4 = new Account("장대호의 계좌1", 200_000_000);
        Account account5 = new Account("장대호의 계좌2", 200_000_000);
        Account account6 = new Account("장대호의 계좌3", 200_000_000);
        Account account7 = new Account("장대호의 계좌4", 200_000_000);
        Account account8 = new Account("장대호의 계좌5", 200_000_000);

        customer1.addAccount(account1);
        customer1.addAccount(account2);
        customer1.addAccount(account3);
        customer2.addAccount(account4);
        customer2.addAccount(account5);
        customer2.addAccount(account6);
        customer2.addAccount(account7);

        for(int i = 0; i < bank.getNumberOfCustomers(); i++){
            Customer customer = bank.getCustomers().get(i);
            printCustomer(customer);
        }
    }

    private static void printCustomer(Customer customer){
        List<Account> accounts = customer.getAccounts();
        System.out.println("------------------------------------");
        System.out.println("주민등록번호: " + customer.getSsn() + ", 성명: " + customer.getName()
                            + ", 보유계좌수: " + customer.getNumberOfAccounts());
        System.out.println("------------------------------------");

        printAccounts(accounts);
        System.out.println("");
    }

    private static void printAccounts(List<Account> accounts){
        int sum = 0;
        for(int i = 0; i < accounts.size(); i++){
            int num = i + 1;
            Account account = accounts.get(i);
            System.out.println(num + ". 계좌명: " + account.getAccountName() +", 잔액: " +
                                account.getBalance()+"원");
            sum += account.getBalance();
        }
        System.out.println("------------------------------------");
        System.out.println("전체 총 잔액: " + sum + "원");
        System.out.println("------------------------------------");
    }
}
