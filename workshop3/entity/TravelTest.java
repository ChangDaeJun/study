package workshop3.entity;

public class TravelTest {
    public static void main(String[] args) {
        TravelBiz travelBiz = new TravelBiz();
        System.out.println("Welcome~ 안녕하세요   여행사입니다.");
        printMenu();

        System.out.print("## 메뉴 입력: ");
        int userInput = Integer.parseInt(TravelUtil.getUserInput());
        while (userInput != 9){
            switch (userInput){
                case 1:
                    travelBiz.printAllTravels();
                    break;
                case 2:
                    travelBiz.printIndividualTravels();
                    break;
                case 3:
                    travelBiz.printPackageTravels();
                    break;
                case 4:
                    System.out.println("여행상품을 예약합니다.");
                    System.out.print("여행 코드 입력: ");
                    String travelCode = TravelUtil.getUserInput();
                    System.out.print("예약 인원 입력: ");
                    int reserveCnt = Integer.parseInt(TravelUtil.getUserInput());
                    Travel travel = travelBiz.reserveTravel(travelCode, reserveCnt);
                    break;
                default:
                    System.out.println("메뉴를 잘못 입력하였습니다.");
                    break;
            }

            printMenu();
            System.out.print("## 메뉴 입력: ");
            userInput = Integer.parseInt(TravelUtil.getUserInput());
        }
    }

    public static void printMenu(){
        System.out.println("======= < 메뉴 > =======");
        System.out.println("1. 전체 여행 상품 조회");
        System.out.println("2. 개별 자유여행 상품 조회");
        System.out.println("3. 패키지여행 상품 조회");
        System.out.println("4. 여행 상품 예약");
        System.out.println("9. 종료");
        System.out.println("=======================");
    }
}
