#include <bits/stdc++.h>
using namespace std;
int N[2030];
//���D���priority_queue �Ƨ�, 2 3 5 ���W��?
//�]���ڤ����D�ۤv���U�g���g�o���ҥH���F�o�����ѣ~\

//���n���S���� pq�S��k�s���X�S�w���
//���L�ڳs��ƫ��ͳ��٨S�d�w �n��@@
//priority_queue<long long, vector<long long>, greater<long long>> pq; //���greater�]�ntype��
int min3( int a, int b, int c ){
    if( a < b && a < c ){
        return a;
    }else if ( b < a && b < c ){
        return b;
    }else{
        return c;
    }
}

//�̫ᤣ��pq ���եΤ�j�p�@
//�����X��
void ugly(){ //�ͦ����
/*
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(5);
*/
    long long a = 2, b = 3, c = 5, num2 = 0, num3 = 0, num5 = 0;
    int i = 1;
    N[0] = 1;
    while( i <= 2030 ){
        N[i] = min3( a, b, c );
        if( N[i] == a ){
            num2++;
            a = N[num2]*2;
        }
        if( N[i] == b){
            num3++;
            b = N[num3]*3;
        }
        if( N[i] == c ){
            num5++;
            c = N[num5]*5;
        }
        i++;
    }
}


int main(){
    ugly();
    int in;

    while(cin >> in){
        cout << N[in-1] << '\n';
    }
}
//���լO���� �[��88
