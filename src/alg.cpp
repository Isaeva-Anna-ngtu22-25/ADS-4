// Copyright 2021 NNTU-CS
  int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) 
            count++;
      }
    }
    return count;
  }

    int countPairs2(int *arr, int len, int value) {
      int count = 0;
      len--;
      while (arr[len] > value) {
        len--;
      }
      for (int i = 0; i < len; i++) {
        for (int j = len; j > i; j--) {
          if (arr[i] + arr[j] == value) {
            count++;
          }
        }
      }
      return count;
    }

      int countPairs3(int *arr, int len, int value) {
        int count = 0;
        for (int i = 0; i < len - 1; i++) {
          int start = i, end = len;
          while (start + 1 < end) {
            int middle = (start + end) / 2;
            if (arr[i] + arr[middle] > value) {
              end = middle;
            } else if (arr[i] + arr[middle] < value) {
              start = middle;
            } else {
              count++;
              int i2 = middle + 1;
              while (arr[i] + arr[i2] == value && i2 < end) {
                count++;
                i2++;
              }
              int i3 = middle - 1;
              while (arr[i] + arr[i3] == value && i3 > start) {
                count++;
                i3--;
              }
              break;
            }
          }
        }
        return count;
      }
