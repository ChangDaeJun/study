package workshop3.entity;

public class TravelBiz {
    private Travel[] travels;

    public TravelBiz() {
        travels = new Travel[5];
        travels[0] = new Travel("TRV001", "뮌헨", "독일항공", Travel.INDIVIDUAL, 10);
        travels[1] = new Travel("TRV002", "프라하", "에어프랑스", Travel.INDIVIDUAL, 7);
        travels[2] = new Travel("TRV003", "LA", "델타항공", Travel.PACKAGE, 12);
        travels[3] = new Travel("TRV004", "후쿠오카", "대한항공", Travel.INDIVIDUAL, 15);
        travels[4] = new Travel("TRV005", "상해", "남방항공", Travel.PACKAGE, 10);

    }

    public void printAllTravels(){
        printTravelListTitle();
        for(Travel travel : travels){
            travel.printTravelInfo();
        }
        System.out.println("-----------------------------------------------------");
    }

    public void printIndividualTravels(){
        printTravelListTitle();
        for(Travel travel : travels){
            if (travel.getTravelType().equals(new String("개별자유여행"))){
                travel.printTravelInfo();
            }
        }
        System.out.println("-----------------------------------------------------");
    }

    public void printPackageTravels(){
        printTravelListTitle();
        for(Travel travel : travels){
            if (travel.getTravelType().equals("패키지여행")){
                travel.printTravelInfo();
            }
        }
        System.out.println("-----------------------------------------------------");
    }

    public Travel reserveTravel(String travelCode, int reserveCount){
        Travel reservingTravel = null;
        for(Travel travel : travels){
            if(travel.getTravelCode().equals(travelCode)){
                reservingTravel = travel;
            }
        }

        if(reservingTravel == null){
            System.out.println("선택한 여행 코드를 찾을 수 없습니다.");
            return null;
        }

        if(reservingTravel.getReserved() + reserveCount > reservingTravel.getMaxPeople()){
            System.out.println("예약 가능 인원이 초과되었습니다. (예약 가능 인원 : "+(reservingTravel.getMaxPeople() - reservingTravel.getReserved())+"명)");
        }
        else{
            System.out.println("예약이 완료 되었습니다.");
        }

        reservingTravel.setReserved(reserveCount);
        return reservingTravel;
    }

    public void printTravelListTitle(){
        System.out.println("-----------------------------------------------------");
        System.out.println("여행코드  도시명     항공편        여행유형  최대예약가능인원 예약");
        System.out.println("-----------------------------------------------------");
    }
}
