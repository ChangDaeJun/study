package algorithm.day1.banking1;

public class BankingTest {
    public static void main(String[] args) {
        Bank bank = new Bank();

        Customer customer1 = new Customer("121212-1212121", "고객1");
        Customer customer2 = new Customer("121212-1212121", "고객2");

        bank.addCustomer(customer1);
        bank.addCustomer(customer2);

        Account account1 = new Account("고객1의 계좌1", 100_000_000);
        Account account2 = new Account("고객1의 계좌2", 100_000_000);
        Account account3 = new Account("고객1의 계좌3", 100_000_000);
        Account account4 = new Account("고객2의 계좌1", 200_000_000);
        Account account5 = new Account("고객2의 계좌2", 200_000_000);
        Account account6 = new Account("고객2의 계좌3", 200_000_000);
        Account account7 = new Account("고객2의 계좌4", 200_000_000);
        Account account8 = new Account("고객2의 계좌5", 200_000_000);

        customer1.addAccount(account1);
        customer1.addAccount(account2);
        customer1.addAccount(account3);
        customer2.addAccount(account4);
        customer2.addAccount(account5);
        customer2.addAccount(account6);
        customer2.addAccount(account7);
        customer2.addAccount(account8);

        printCustomersOf(bank);
    }

    private static void printCustomersOf(Bank bank){
        for(int i = 0; i < bank.getNumberOfCustomers(); i++){
            Customer customer = bank.getCustomers()[i];

            System.out.println("--------------------------------------------------------");
            System.out.println("주민등록번호: " + customer.getSsn() + ", 성명: " + customer.getName()
                    + ", 보유계좌수: " + customer.getNumberOfAccounts());
            System.out.println("-------------------------------------------------------");

            printAccountsOf(customer);

            System.out.println("");
        }
    }

    private static void printAccountsOf(Customer customer){
        int sum = 0;

        for(int i = 0; i < customer.getNumberOfAccounts(); i++){
            int num = i + 1;
            Account account = customer.getAccounts()[i];
            System.out.println(num + ". 계좌명: " + account.getAccountName() +", 잔액: " +
                                account.getBalance()+"원");
            sum += account.getBalance();
        }

        System.out.println("--------------------------------------------------------");
        System.out.println("전체 총 잔액: " + sum + "원");
        System.out.println("--------------------------------------------------------");
    }
}
