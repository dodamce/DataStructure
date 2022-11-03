public class KMP {

    public static void InitNext(String dst, int[] next) {
        next[0] = -1;
        next[1] = 0;
        int k = 0;
        for (int i = 2; i < dst.length(); i++) {
            // 找str[i-1]==str[k]位置
            while (k != -1 && dst.charAt(i - 1) != dst.charAt(k)) {
                k = next[k];
            }
            next[i] = k + 1;
        }
    }

    // 使用KMP算法返回src第一个匹配dst的位置,下标从0开始,从dst的pos位置开始匹配
    public static int GetSubStrPos(String src, String dst, int pos) {
        if (src == null || dst == null || src.length() == 0 || dst.length() == 0)
            return -1;
        if (pos >= dst.length() || pos < 0)
            return -1;

        int i = 0;// 遍历src主串
        int j = pos;// 遍历dst字串
        int lenSrc = src.length();
        int lenDst = dst.length();
        // 计算字串的next数组
        int[] next = new int[lenDst];
        InitNext(dst, next);

        while (i < lenSrc && j < lenDst) {
            if (src.charAt(i) == dst.charAt(j)) {
                i++;
                j++;
            } else {
                // i不回退
                j = next[j];
            }
        }
        if (j >= lenDst) {
            // 匹配成功，返回i-j
            return i - j;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        // System.out.println(GetSubStrPos("abcabcabcdabcde", "abcd", 0));
        System.out.println(GetSubStrPos("abcdabcabcdabcde", "abcd", 0));
    }
}
