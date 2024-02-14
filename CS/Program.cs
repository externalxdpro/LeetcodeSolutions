using LeetcodeSolutions;

public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null)
    {
        this.val = val;
        this.next = next;
    }
}

internal class Program
{
    private static void Main(string[] args)
    {
        // AddTwoNumbers_2 solution = new AddTwoNumbers_2();
        // ListNode c1 = new ListNode(3), b1 = new ListNode(4, c1), a1 = new ListNode(2, b1), c2 = new ListNode(4), b2 = new ListNode(6, c2), a2 = new ListNode(5, b2);
        // ListNode a1 = new ListNode(0), a2 = new ListNode(0);
        // ListNode g1 = new ListNode(9), f1 = new ListNode(9, g1), e1 = new ListNode(9, f1), d1 = new ListNode(9, e1), c1 = new ListNode(9, d1), b1 = new ListNode(9, c1), a1 = new ListNode(9, b1), d2 = new ListNode(9), c2 = new ListNode(9, d2), b2 = new ListNode(9, c2), a2 = new ListNode(9, b2);
        // ListNode a1 = new ListNode(0), b2 = new ListNode(3), a2 = new ListNode(7, b2);
        // Console.WriteLine(solution.AddTwoNumbers(a1, a2).val);

        // LongestSubstringWithoutRepeatingCharacters_3 solution = new LongestSubstringWithoutRepeatingCharacters_3();
        // Console.WriteLine(solution.LengthOfLongestSubstring("123321"));
        // Console.WriteLine(solution.LengthOfLongestSubstring("pwwkew"));

        // MedianOfTwoSortedArrays_4 solution = new MedianOfTwoSortedArrays_4();
        // int[] nums1 = {1, 3}, nums2 = {2};
        // int[] nums1 = {1, 2}, nums2 = {3, 4};
        // Console.WriteLine(solution.FindMedianSortedArrays(nums1, nums2));

        // LongestPalindromicSubstring_5 solution = new LongestPalindromicSubstring_5();
        // Console.WriteLine(solution.LongestPalindrome("babad"));
        // Console.WriteLine(solution.LongestPalindrome("bbb"));
        // Console.WriteLine(solution.LongestPalindrome("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy"));
        // Console.WriteLine(solution.LongestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"));

        // ZigzagConversion_6 solution = new ZigzagConversion_6();
        // Console.WriteLine(solution.Convert("PAYPALISHIRING", 3));
        // Console.WriteLine(solution.Convert("ABCDE", 2));

        // ReverseInteger_7 solution = new ReverseInteger_7();
        // Console.WriteLine(solution.Reverse(1534236469));

        // StringToInteger_8 solution = new StringToInteger_8();
        // Console.WriteLine(solution.MyAtoi("-91283472332"));
        // Console.WriteLine(solution.MyAtoi("+-12"));

        // PalindromeNumber_9 solution = new PalindromeNumber_9();
        // Console.WriteLine(solution.IsPalindrome(121));

        // ContainerWithMostWater_11 solution = new ContainerWithMostWater_11();
        // int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        // int[] height = {1, 1};
        // Console.WriteLine(solution.MaxArea(height));

        // IntegerToRoman_12 solution = new IntegerToRoman_12();
        // Console.WriteLine(solution.IntToRoman(3));
        // Console.WriteLine(solution.IntToRoman(58));
        // Console.WriteLine(solution.IntToRoman(1994));

        ThreeSum_15 solution = new ThreeSum_15();
        int[] nums = new int[] {-1, 0, 1, 2, -1, -4};
        // Console.WriteLine(String.Join(", ", solution.ThreeSum(nums)));
        foreach (List<int> list in solution.ThreeSum(nums))
            System.Console.WriteLine(String.Join(", ", list));

        // LetterCombinationsOfAPhoneNumber_17 solution = new LetterCombinationsOfAPhoneNumber_17();
        // Console.WriteLine(String.Join(", ", solution.LetterCombinations("23")));
        // Console.WriteLine(String.Join(", ", solution.LetterCombinations("")));
        // Console.WriteLine(String.Join(", ", solution.LetterCombinations("2")));
        // Console.WriteLine(String.Join(", ", solution.LetterCombinations("2345")));

        // RemoveNthNodeFromEndOfList_19 solution = new RemoveNthNodeFromEndOfList_19();
        // ListNode e = new ListNode(5), d = new ListNode(4, e), c = new ListNode(3, d), b = new ListNode(2, c), head = new ListNode(1, b); int n = 2;
        // ListNode head = new ListNode(1); int n = 1;
        // ListNode b = new ListNode(2), head = new ListNode(1, b); int n = 1;
        // ListNode b = new ListNode(2), head = new ListNode(1, b); int n = 2;
        // ListNode c = new ListNode(3), b = new ListNode(2, c), head = new ListNode(1, b); int n = 2;
        // ListNode pointer = head;
        // while (pointer != null)
        // {
        //     Console.Write($"{solution.RemoveNthFromEnd(pointer, n).val}, ");
        //     pointer = pointer.next;
        // }

        // strStr_28 solution = new strStr_28();
        // Console.WriteLine(solution.StrStr("aaaaaaa", "bba"));

        // DivideTwoIntegers_29 solution = new DivideTwoIntegers_29();
        // Console.WriteLine(solution.Divide(10, 3));
        // Console.WriteLine(solution.Divide(7, -3));
        // Console.WriteLine(solution.Divide(0, 1));
        // Console.WriteLine(solution.Divide(-2147483648, -1));

        // SearchInRotatedSortedArray_33 solution = new SearchInRotatedSortedArray_33();
        // int[] nums = {4, 5, 6, 7, 0, 1, 2}; int target = 0;
        // int[] nums = {4, 5, 6, 7, 0, 1, 2}; int target = 3;
        // int[] nums = {1}; int target = 0;
        // Console.WriteLine(solution.Search(nums, target));

        // FindFirstAndLastPositionOfElementInSortedArray_34 solution = new FindFirstAndLastPositionOfElementInSortedArray_34();
        // int[] nums = {5, 7, 7, 8, 8, 10}; int target = 8;
        // int[] nums = {5, 7, 7, 8, 8, 10}; int target = 6;
        // int[] nums = {}; int target = 0;
        // int[] nums = {1}; int target = 1;
        // foreach (int num in solution.SearchRange(nums, target))
        //     Console.Write($"{num}, ");

        // SearchInsertPosition_35 solution = new SearchInsertPosition_35();
        // int[] nums = {1, 3, 5, 6};
        // Console.WriteLine(solution.SearchInsert(nums, 5));

        // Pow_50 solution = new Pow_50();
        // Console.WriteLine(solution.MyPow(1.00000, 2147483647));

        // LengthOfLastWord_58 solution = new LengthOfLastWord_58();
        // Console.WriteLine(solution.LengthOfLastWord("   fly me   to   the moon  "));

        // PlusOne_66 solution = new PlusOne_66();
        // int[] digits = {9, 9};
        // foreach (int digit in solution.PlusOne(digits))
        // {
        //     Console.Write($"{digit}, ");
        // }

        // Sqrt_69 solution = new Sqrt_69();
        // Console.WriteLine(solution.MySqrt(4));
        // Console.WriteLine(solution.MySqrt(8));
        // Console.WriteLine(solution.MySqrt(Int32.MaxValue));

        // SearchA2DMatrix_74 solution = new SearchA2DMatrix_74();
        // int[] row0 = {1, 3, 5, 7}, row1 = {10, 11, 16, 20}, row2 = {23, 30, 34, 60}; int[][] matrix = new int[][] {row0, row1, row2}; int target = 3;
        // int[] row0 = {1, 3, 5, 7}, row1 = {10, 11, 16, 20}, row2 = {23, 30, 34, 60}; int[][] matrix = new int[][] {row0, row1, row2}; int target = 13;
        // int[] row0 = {1}; int[][] matrix = new int[][] {row0}; int target = 0;
        // int[] row0 = {1, 3, 5}; int[][] matrix = new int[][] {row0}; int target = 1;
        // Console.WriteLine(solution.SearchMatrix(matrix, target));

        // FindMinimumInRotatedSortedArray_153 solution = new FindMinimumInRotatedSortedArray_153();
        // int[] nums = {3, 4, 5, 1, 2};
        // int[] nums = {4, 5, 6, 7, 0, 1, 2};
        // int[] nums = {11, 13, 15, 17};
        // Console.WriteLine(solution.FindMin(nums));

        // TwoSumII_167 solution = new TwoSumII_167();
        // int[] numbers = {2, 7, 11, 15}; int target = 9;
        // int[] numbers = {2, 3, 4}; int target = 6;
        // int[] numbers = {-1, 0}; int target = -1;
        // foreach (int num in solution.TwoSum(numbers, target))
        //     Console.Write($"{num}, ");

        // RotateArray_189 solution = new RotateArray_189();
        // int[] nums = {1, 2, 3, 4, 5, 6, 7}; int k = 3;
        // int[] nums = {-1, -100, 3, 99}; int k = 2;
        // int[] nums = {1, 2}; int k = 3;
        // solution.Rotate(nums, k);
        // Console.WriteLine(String.Join(", ", nums));

        // FirstBadVersion_278 solution = new FirstBadVersion_278();
        // Console.WriteLine(solution.FirstBadVersion(5, 4));
        // Console.WriteLine(solution.FirstBadVersion(1, 1));

        // MoveZeroes_283 solution = new MoveZeroes_283();
        // int[] nums = {0, 1, 0, 3, 12};
        // int[] nums = {0};
        // solution.MoveZeroes(nums);
        // Console.WriteLine(String.Join(", ", nums));

        // ReverseString_344 solution = new ReverseString_344();
        // char[] s = {'h', 'e', 'l', 'l', 'o'};
        // char[] s = {'H', 'a', 'n', 'n', 'a', 'h'};
        // solution.ReverseString(s);
        // Console.WriteLine(String.Join(", ", s));

        // IntersectionOfTwoArraysII_350 solution = new IntersectionOfTwoArraysII_350();
        // int[] nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
        // int[] nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
        // Console.WriteLine(String.Join(", ", solution.Intersect(nums1, nums2)));

        // ValidPerfectSquare_367 solution = new ValidPerfectSquare_367();
        // Console.WriteLine(solution.IsPerfectSquare(16));
        // Console.WriteLine(solution.IsPerfectSquare(14));
        // Console.WriteLine(solution.IsPerfectSquare(2147483647));

        // GuessNumberHigherOrLower_374 solution = new GuessNumberHigherOrLower_374();
        // Console.WriteLine(solution.GuessNumber(10, 6));
        // Console.WriteLine(solution.GuessNumber(1, 1));
        // Console.WriteLine(solution.GuessNumber(2, 1));
        // Console.WriteLine(solution.GuessNumber(2126753390, 1702766719));

        // ArrangingCoins_441 solution = new ArrangingCoins_441();
        // Console.WriteLine(solution.ArrangeCoins(5));
        // Console.WriteLine(solution.ArrangeCoins(8));
        // Console.WriteLine(solution.ArrangeCoins(1804289383));

        // ReverseWordsInAStringIII_557 solution = new ReverseWordsInAStringIII_557();
        // Console.WriteLine(solution.ReverseWords("Let's take LeetCode contest"));
        // Console.WriteLine(solution.ReverseWords("God Ding"));

        // SumOfSquareNumber_633 solution = new SumOfSquareNumber_633();
        // Console.WriteLine(solution.JudgeSquareSum(5));
        // Console.WriteLine(solution.JudgeSquareSum(3));
        // Console.WriteLine(solution.JudgeSquareSum(0));
        // Console.WriteLine(solution.JudgeSquareSum(999999999));

        // BinarySearch_704 solution = new BinarySearch_704();
        // int[] nums = {-1, 0, 3, 5, 9, 12}; int target = 9;
        // int[] nums = {-1, 0, 3, 5, 9, 12}; int target = 2;
        // Console.WriteLine(solution.Search(nums, target));

        // FindSmallestLetterGreaterThanTarget_744 solution = new FindSmallestLetterGreaterThanTarget_744();
        // char[] letters = {'c','f','j'}; char target = 'a';
        // char[] letters = {'c','f','j'}; char target = 'c';
        // char[] letters = {'c', 'f', 'j'}; char target = 'd';
        // char[] letters = {'c', 'f', 'j'}; char target = 'k';
        // char[] letters = {'c', 'f', 'j'}; char target = 'g';
        // char[] letters = {'e','e','e','e','e','e','n','n','n','n'}; char target = 'n';
        // char[] letters = { 'e', 'e', 'e', 'k', 'q', 'q', 'q', 'v', 'v', 'y' }; char target = 'v';
        // Console.WriteLine(solution.NextGreatestLetter(letters, target));

        // PeakIndexInAMountainArray_852 solution = new PeakIndexInAMountainArray_852();
        // int[] arr = {0, 1, 0};
        // int[] arr = {0, 2, 1, 0};
        // int[] arr = {0, 10, 5, 2};
        // Console.WriteLine(solution.PeakIndexInMountainArray(arr));

        // MiddleOfTheLinkedList_876 solution = new MiddleOfTheLinkedList_876();
        // ListNode e = new ListNode(5), d = new ListNode(4, e), c = new ListNode(3, d), b = new ListNode(2, c), head = new ListNode(1, b);
        // ListNode f = new ListNode(6), e = new ListNode(5, f), d = new ListNode(4, e), c = new ListNode(3, d), b = new ListNode(2, c), head = new ListNode(1, b);
        // Console.WriteLine(solution.MiddleNode(head).val);

        // SquaresOfASortedArray_977 solution = new SquaresOfASortedArray_977();
        // int[] nums = {-4, -1, 0, 3, 10};
        // int[] nums = {-7, -3, 2, 3, 11};
        // Console.WriteLine(String.Join(", ", solution.SortedSquares(nums)));

        // TheKWeakestRowsInAMatrix_1337 solution = new TheKWeakestRowsInAMatrix_1337();
        // int[] row0 = new int[] {1,1,0,0,0}; int[] row1 = new int[] {1,1,1,1,0}; int[] row2 = new int[] {1,0,0,0,0}; int[] row3 = new int[] {1,1,0,0,0}; int[] row4 = new int[] {1,1,1,1,1}; int[][] mat = new int[][] {row0, row1, row2, row3, row4}; int k = 3;
        // int[] row0 = new int[] {1,0,0,0}; int[] row1 = new int[] {1,1,1,1}; int[] row2 = new int[] {1,0,0,0}; int[] row3 = new int[] {1,0,0,0}; int[][] mat = new int[][] {row0, row1, row2, row3}; int k = 2;
        // int[] row0 = new int[] {1,0}; int[] row1 = new int[] {0,0}; int[] row2 = new int[] {1,0}; int[][] mat = new int[][] {row0, row1, row2}; int k = 2;
        // Console.WriteLine(String.Join(", ", solution.KWeakestRows(mat, k)));

        // CheckIfNAndItsDoubleExist_1346 solution = new CheckIfNAndItsDoubleExist_1346();
        // int[] arr = {10, 2, 5, 3};
        // int[] arr = {3, 1, 7, 11};
        // int[] arr = {-10, 12, -20, -8, 15};
        // int[] arr = {-2, 0, 10, -19, 4, 6, -8};
        // Console.WriteLine(solution.CheckIfExist(arr));

        // CountNegativeNumbersInASortedMatrix_1351 solution = new CountNegativeNumbersInASortedMatrix_1351();
        // int[] row0 = {4, 3, 2, -1}, row1 = {3, 2, 1, -1}, row2 = {1, 1, -1, -2}, row3 = {-1, -1, -2, -3}; int[][] grid = new int[][] {row0, row1, row2, row3};
        // int[] row0 = {3, 2}, row1 = {1, 0}; int[][] grid = new int[][] {row0, row1};
        // Console.WriteLine(solution.CountNegatives(grid));

        // FindTheDistanceValueBetweenTwoArrays_1385 solution = new FindTheDistanceValueBetweenTwoArrays_1385();
        // int[] arr1 = {4, 5, 8}, arr2 = {10, 9, 1, 8}; int d = 2;
        // int[] arr1 = {1, 4, 2, 3}, arr2 = {-4, -3, 6, 10, 20, 30}; int d = 3;
        // int[] arr1 = {2, 1, 100, 3}, arr2 = {-5, -2, 10, -3, 7}; int d = 6;
        // int[] arr1 = {-803,715,-224,909,121,-296,872,807,715,407,94,-8,572,90,-520,-867,485,-918,-827,-728,-653,-659,865,102,-564,-452,554,-320,229,36,722,-478,-247,-307,-304,-767,-404,-519,776,933,236,596,954,464}, arr2 = {817,1,-723,187,128,577,-787,-344,-920,-168,-851,-222,773,614,-699,696,-744,-302,-766,259,203,601,896,-226,-844,168,126,-542,159,-833,950,-454,-253,824,-395,155,94,894,-766,-63,836,-433,-780,611,-907,695,-395,-975,256,373,-971,-813,-154,-765,691,812,617,-919,-616,-510,608,201,-138,-669,-764,-77,-658,394,-506,-675,523,730,-790,-109,865,975,-226,651,987,111,862,675,-398,126,-482,457,-24,-356,-795,-575,335,-350,-919,-945,-979,611}; int d = 37;
        // Console.WriteLine(solution.FindTheDistanceValue(arr1, arr2, d));

        // KthMissingPositiveNumber_1539 solution = new KthMissingPositiveNumber_1539();
        // int[] arr = {2, 3, 4, 7, 11}; int k = 5;
        // int[] arr = {1, 2, 3, 4}; int k = 2;
        // Console.WriteLine(solution.FindKthPositive(arr, k));

        // SpecialArrayWithXElementsGreaterThanOrEqualX_1608 solution = new SpecialArrayWithXElementsGreaterThanOrEqualX_1608();
        // int[] nums0 = {3, 5};
        // int[] nums1 = {0, 0};
        // int[] nums2 = {0, 4, 3, 0, 4};
        // int[] nums3 = {3, 6, 7, 7, 0};
        // List<int[]> numsArrs = new List<int[]>() {nums0, nums1, nums2, nums3};
        // foreach (int[] nums in numsArrs)
        //     Console.WriteLine(solution.SpecialArray(nums));

        // MaximumDistanceBetweenAPairOfValues_1855 solution = new MaximumDistanceBetweenAPairOfValues_1855();
        // int[] nums1 = {55, 30, 5, 4, 2}, nums2 = {100, 20, 10, 10, 5};
        // int[] nums1 = {2, 2, 2}, nums2 = {10, 10, 1};
        // int[] nums1 = {30, 29, 19, 5}, nums2 = {25, 25, 25, 25, 25};
        // Console.WriteLine(solution.MaxDistance(nums1, nums2));
    }
}
