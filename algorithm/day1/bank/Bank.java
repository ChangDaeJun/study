package algorithm.day1.bank;

public class Bank {
    private Customer[] customers;
    private int numberOfCustomers;

    public Bank() {
        customers = new Customer[10];
        numberOfCustomers = 0;
    }

    public Customer[] getCustomers() {
        return customers;
    }

    public int getNumberOfCustomers() {
        return numberOfCustomers;
    }

    public void addCustomer(Customer customer){
        if(numberOfCustomers >= 10){
            System.out.println("손님은 10명을 이상 등록할 수 없습니다. ");
            return;
        }
        customers[numberOfCustomers] = customer;
        numberOfCustomers++;
    }
}
