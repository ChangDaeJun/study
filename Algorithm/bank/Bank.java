package Algorithm.bank;

import java.util.ArrayList;
import java.util.List;

public class Bank {
    private List<Customer> customers;
    private int numberOfCustomers;

    public Bank() {
        customers = new ArrayList<>();
        numberOfCustomers = 0;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public int getNumberOfCustomers() {
        return numberOfCustomers;
    }

    public void addCustomer(Customer customer){
        if(customers.size() >= 10){
            System.out.println("손님은 10명을 이상 등록할 수 없습니다. ");
            return;
        }
        customers.add(customer);
        numberOfCustomers++;
    }
}
