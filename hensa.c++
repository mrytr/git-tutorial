#include <stdio.h>
#include <math.h>

void sort(int N[], int len){
	int i, j, num;

	for(i=0;i<len;i++){
		for(j=len-1;j>i;j--){
			if(N[j]<N[j-1]){
				num=N[j];
				N[j]=N[j-1];
				N[j-1]=num;
			}
		}
	}
}

int main(){
	int rika[20]={65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
	int eigo[20]={44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
	double  rihen[20]={0};
	double eihen[20]={0};
	double rave=0.0, eave=0.0, rhen = 0.0, ehen = 0.0;
	int rsum = 0, esum = 0;
	int i;

	for (i=0;i<20;i++){
		rsum += rika[i];
		esum += eigo[i];
	}
	rave = rsum/20;
	eave = esum/20;

	for (i=0;i<20;i++){
		rhen += (rika[i]-rave)*(rika[i]-rave);
		ehen += (eigo[i]-eave)*(eigo[i]-eave);
	}
	rhen /= 20;
	ehen /= 20;
	rhen = sqrt(rhen);
	ehen = sqrt(ehen);

	for (i=0;i<20;i++){
		rihen[i] = ((rika[i]-rave)/rhen)*10+50;
		eihen[i] = ((eigo[i]-eave)/ehen)*10+50;
	}

	printf("goukei rika:%d eigo:%d\n", rsum, esum);
	printf("heikin rika:%lf eigo:%lf\n", rave, eave);
	printf("hyoujyunhensa rika:%lf eigo:%lf\n", rhen, ehen);

	for (i=0;i<20;i++){
		printf("%lf %lf\n", rihen[i], eihen[i]);
	}

	sort(rika, 20);
	sort(eigo, 20);
	for (i=19;i>=0;i--){
		printf("%d %d\n", rika[i], eigo[i]);
	}
}
