#ifndef _mergersort_h
#define _mergersort_h

void Divide(float *dataset, int first, int last, float *sortset);
void Merge(float *dataset,int first, int mid, int last, float *sortset);
void MergeSort(float *dataset, int size);

#endif




