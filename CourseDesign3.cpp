#include<iostream>
using namespace std;
#define A 1
#define J 11
#define Q 12
#define K 13
int G1[13] = { 10, Q, A, 5, 2, 6, K, 3, 8, 9, 7, J, 4 };
int G2[13] = { 3, 6, 7, A, 10, K, 4, 2, J, Q, 9, 5, 8};
int G3[13] = { 4, A, 3, K, J, 10, 6, Q, 8, 9, 5, 7, 2};
void shuffle(int a[], int num, int way[], int times);
int find_order(int a[], int num, int way[]);
void print(int a[], int num);
int main()
{
	int G[13] = { A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};
	int r1 = 2, r2 = 0, r3 = 3;
	cout << "G按G1洗r1="<<r1<<"次：" ;
	shuffle(G, 13, G1,r1);
	print(G,13);
	cout << endl;
	cout << "再按G2洗r2=" << r2 << "次：";
	shuffle(G, 13, G2, r2);
	print(G, 13);
	cout << endl;
	cout << "再按G3洗r3=" << r3 << "次：";
	shuffle(G, 13, G3, r3);
	print(G, 13);
	int g11[13] = { 10, Q, A, 5, 2, 6, K, 3, 8, 9, 7, J, 4 };
	int g22[13] = { 3, 6, 7, A, 10, K, 4, 2, J, Q, 9, 5, 8 };
	int g33[13] = { 4, A, 3, K, J, 10, 6, Q, 8, 9, 5, 7, 2 };
	int ordG1=find_order(g11, 13, G1);
	int ordG2=find_order(g22, 13, G2);
	int ordG3=find_order(g33, 13, G3);
	cout << endl;
	cout <<"G1的阶为ordG1："<<ordG1<<endl<< "G2的阶为ordG2：" << ordG2<<endl<< "G2的阶为ordG3：" << ordG3 << endl;
	cout << "\nG按G3洗ordG3-r3=" << (ordG3 - r3)%ordG3 << "(mod"<<ordG3<<")次 ";
	shuffle(G, 13, G3, ordG3-r3);
	print(G, 13);
	cout << "\n再按G2洗ordG2-r2=" << (ordG2 - r2) % ordG2 << "(mod" << ordG2 << ")次 ";
	shuffle(G, 13, G2, ordG2-r2);
	print(G, 13);
	cout << "\n再按G1洗ordG1-r1=" << (ordG1 - r1) % ordG1 << "(mod" << ordG1 << ")次 ";
	shuffle(G, 13, G1, ordG1-r1);
	print(G, 13);
}
void shuffle(int a[], int num, int way[], int times)
{
	for (int t = 0;t < times;t++)
	{
		for (int i = 0;i < num;i++)
		{
			a[i] = way[a[i] - 1];
		}
	}
}
int find_order(int a[], int num, int way[])
{
	int i = 1;
	while (1)
	{
		int flag = 0;
		shuffle(a, num, way, 1);
		for (int j = 0;j < num;j++)
		{
			if (a[j] == way[j] )
				flag++;
			else break;
			if (flag == num)
			{
				return i;
			}
		}
		i++;
	}

}
void print(int a[], int num)
{
	cout << "G（";
	for (int i = 0;i < num;i++)
	{
		switch (a[i])
		{
		case 1:cout << "A"; break;
		case 11:cout << "J"; break;
		case 12:cout << "Q"; break;
		case 13:cout << "K"; break;
		default:cout << a[i]; break;
		}
		cout << " ";
	}
	cout << "）" << endl;
}