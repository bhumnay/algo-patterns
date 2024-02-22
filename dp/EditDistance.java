public class EditDistance {
    public static int getEditDistance(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        String small = str1;
        String large = str2;
        if (len1 > len2) {
            small = str2;
            large = str1;
        }

        int[] prev = new int[small.length() + 1];
        int curr[] = new int[small.length() + 1];

        for (int i = 0; i <= small.length(); i++) {
            prev[i] = i;
        }
        for (int i = 1; i <= large.length(); i++) {
            curr[0] = i;
            for (int j = 1; j <= small.length(); j++) {
                if (large.charAt(i - 1) == small.charAt(j - 1)) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + Math.min(prev[j], Math.min(prev[j - 1], curr[j - 1]));
                }
            }
            for (int j = 0; j <= small.length(); j++) {
                prev[j] = curr[j];
            }
        }
        return curr[small.length()];
    }

    public static void main(String[] args) {
        String str1 = "sunday";
        String str2 = "saturday";
        System.out.println(getEditDistance(str1, str2));
    }
}
