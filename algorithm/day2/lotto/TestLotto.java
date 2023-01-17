package algorithm.day2.lotto;

import java.util.Map;

public class TestLotto {
    public static void main(String[] args) {
        int[] lottoNumbers = Lotto.generateLottoNumbers();
        Lotto.sortLottoNumbers(lottoNumbers);
        Lotto.displayLottoNumbers(lottoNumbers);
    }
}
