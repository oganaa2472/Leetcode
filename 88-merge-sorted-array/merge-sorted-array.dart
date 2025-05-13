class Solution {
  void merge(List<int> nums1, int m, List<int> nums2, int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  List<int> answer = List.filled(m + n, 0);

  while (i < m && j < n) {
    if (nums1[i] >= nums2[j]) {
      answer[k++] = nums2[j++];
    } else {
      answer[k++] = nums1[i++];
    }
  }

  while (i < m) {
    answer[k++] = nums1[i++];
  }

  while (j < n) {
    answer[k++] = nums2[j++];
  }

  // Replace nums1 content with merged result
  nums1.clear();
  nums1.addAll(answer);
}

}