//이진탐색 알고리즘
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, i;
	int* tree_list;
	long long left, mid, right, sum, max, cut_max;

	scanf("%d %d", &n, &m); //나무의 수 n, 가져갈 나무 길이 m
	tree_list = (int*)malloc(n * sizeof(int)); //나무의 수 만큼 동적할당

	for (i = 0, max = 0; i < n; i++) {
		scanf(" %d", &tree_list[i]); //동적배열에 나무 1개씩 입력

		//나무 중 제일 긴 나무의 길이 저장
		if (max < tree_list[i]) {
			max = tree_list[i];
		}
	}

	left = 1, right = max, cut_max = 0;
	//나무 중 제일 긴 나무를 리스트 맨 끝으로 설정하고(오른쪽)
	//왼쪽은 가장 작은 숫자 1로 두어 이진탐색을 반복한다.
	while (left <= right) {
		//절단기 높이
		mid = (right + left) / 2;
		
		for (i = 0, sum = 0; i < n; i++) {
			//절단기 높이보다 긴 나무의 경우에만 sum
			if (tree_list[i] - mid > 0) {
				sum = sum + (tree_list[i] - mid);
			}
		}
		//가져갈 나무의 길이에 못미치므로 절단기 높이를 낮춰야한다
		if (sum < m) {
			right = mid - 1;
		}
		//절단기 길이를 더 높여도된다
		else {
			//절단기의 최대높이 갱신
			if (cut_max < mid) {
				cut_max = mid;
			}
			left = mid + 1;
		}
	}
	printf("%lld\n", cut_max);

	free(tree_list);
	return 0;
}
