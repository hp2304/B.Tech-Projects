#include <stdio.h>
#include <stdlib.h>
#include "sort_arr.h"				/* sort_arr.h generated by rpcgen */
 
// int *
// printmessage_1_svc(msg, req)
// 	struct list *msg;	
// 	struct svc_req *req;		/* details of call */
// {
// 	static int result = 0;			/* must be static! */
// 	for(int i=0; i<msg->nums.nums_len; i++){
// 		printf("num : %d\n", msg->nums.nums_val[i]);
// 		result += msg->nums.nums_val[i];
// 	}
// 	return (&result);
// }

struct list *sort_1_svc(struct list *obj, struct svc_req *req){
	printf("\n\n\nGot client request...\n");
	static struct list res;
	int n = (*obj).nums.nums_len;
	res.nums.nums_len = n;
	res.nums.nums_val = (int *) calloc(n, sizeof(int));;
	//memcpy(res.nums.nums_val, (*obj).nums.nums_val, n);
	for(int i=0; i<n; ++i){
		res.nums.nums_val[i] = (*obj).nums.nums_val[i];
	}
	printf("Got array of size %d.\n", res.nums.nums_len);
	for(int i=0; i<res.nums.nums_len; ++i){
		printf("%d ", res.nums.nums_val[i]);
	}
	printf("\nPerforming sorting algorithm...");
	int val, j;
	for(int i=1; i<n; ++i){
		j = i-1;
		val = res.nums.nums_val[i];
		while(j>=0){
			if(val < res.nums.nums_val[j])
				res.nums.nums_val[j+1] = res.nums.nums_val[j];
			else
				break;
			--j;
		}
		res.nums.nums_val[j+1] = val;
	}
	printf("\nReturning sorted array...");
	return (&res);
}