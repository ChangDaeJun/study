package workshop3.entity;

public class Travel {
    private String travelCode;
    private String cityName;
    private String flight;
    private int travelType;
    private int maxPeople;
    private int reserved = 0;
    public static int INDIVIDUAL = 0;
    public static int PACKAGE = 1;

    public Travel(String travelCode, String cityName, String flight, int travelType, int maxPeople) {
        this.travelCode = travelCode;
        this.cityName = cityName;
        this.flight = flight;
        this.travelType = travelType;
        this.maxPeople = maxPeople;
    }

    public String getTravelCode() {
        return travelCode;
    }

    public String getCityName() {
        return cityName;
    }

    public String getFlight() {
        return flight;
    }

    public String getTravelType() {
        if (this.travelType == INDIVIDUAL) return "개별자유여행";
        else if(this.travelType == PACKAGE) return "패키지여행";

        return "error";
    }

    public int getMaxPeople() {
        return maxPeople;
    }

    public int getReserved() {
        return reserved;
    }

    public void setReserved(int reserved) {
        this.reserved += reserved;
    }

    public void printTravelInfo(){
        System.out.printf("%-6s  %-4s \t %-5s \t %-6s \t %2d명 \t %-1d명 \n", this.travelCode, this.cityName, this.flight, getTravelType(), this.maxPeople, this.reserved);
    }

}
