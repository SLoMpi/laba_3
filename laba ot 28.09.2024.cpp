#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <cmath>
int MySwap(int &a, int &b) {
    int s = a;
    a = b;
    b = s;
}
using namespace std;
template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}


int main() {
    while (true) {
        int d;
        cout<< "Выберите задание:\n"
        << "1. \n"
        << "2. \n"
        << "3. \n"
        << "4. \n"
        << "5. \n"
        << "6. \n"
        << "7. \n"
        << "8. \n"
        << "9. \n"
        << "10. \n"
        << "11. \n"
        << "0. Выход\n";
        std:cin >> d;
        if (d == 0) break;
        switch (d) {
            case 1: {
                vector<int> v = generate_random_vector<int>(10, -100, 50);
                cout<<endl;
                int a;
                int first=v[0];
                cout<<"Введите а:";
                cin>>a;
                cout<<"Изначальный масив:";
                for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
                cout<<endl;
                for(int i=0;i<v.size();i++) {
                    cout<<v[i]*2<<" ";
                }
                cout<<endl;
                for(int i=0;i<v.size();i++) {
                    cout<<v[i]-a<<" ";
                }
                cout<<endl;
                if (first!=0) {
                    for(int i=0;i<v.size();i++) {
                        cout<<(float)v.at(i)/first<<" ";
                    }
                }
                cout<<endl;
                break;
            }
            case 2: {
                vector<int> v = generate_random_vector<int>(10, -100, 50);
                int sum=0,sum2=0,sum6=0,k1,k2,sumk=0,s1,s2,sums=0;
                float srarefm;
                for(int i=0;i<v.size();i++) {
                    sum+=v[i];
                }
                cout<<"сумму всех элементов массива"<<sum<<endl;
                for(int i=0;i<v.size();i++) {
                    sum2+=pow(v[i],2);
                }
                cout<<sum2<<endl;
                for(int i=0;i<6;i++) {
                    sum6+=v[i];
                }
                cout<<sum6<<endl;
                cout<<"Введите k1 и k2(k2>k1): ";
                cin>>k1,k2;
                k1-=1;
                for(int i=k1;i<k2;i++) {
                    sumk+=v[i];
                }
                cout<<sumk<<endl;
                cout<<sum/v.size()<<endl;
                cout<<"Введите s1,s2:";
                cin>>s1,s2;
                for(int i=s1-1;i<s2;i++) {
                    sums+=v[i];
                }
                cout<<sums/(s2-s1-1)<<endl;
                break;
            }
            case 3: {
                vector<int> v = generate_random_vector<int>(20, -100, 50);
                for(int i=0;i<v.size();i++) {
                    cout<<v[i]<<" ";
                }
                cout<<endl;
                MySwap(v[0],v[v.size()-3]);
                MySwap(v[1],v[v.size()-2]);
                MySwap(v[2],v[v.size()-1]);
                for(int i=0;i<v.size();i++) {
                    cout<<v[i]<<" ";
                }
                break;
            }
            case 4: {
                vector<int> v = generate_random_vector<int>(10, -100, 50);
                vector<int> v2(v.size()-1);
                vector<int> v3(v.size()-1);
                cout<<"Изначальный масив: ";
                for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
                cout<<endl;
                int iterasion1=-1,iterasion2=-1;
                for(int i=0;i<v.size();i++) {
                    if (v[i]<0) {
                        iterasion1=i;
                        break;
                    }
                }
                cout<<" масив 2: ";
                if (iterasion1!=-1) {
                    for(int i = 0; i < v.size() - 1; i++) {
                        if (iterasion1 != i) {
                            v2[i] = v[i];
                            cout<<v2[i]<<" ";
                        }
                    }
                    cout<<endl;
                }else cout<<"\n В масиве отсутствуют отрицательные эллементы"<<endl;
                for(int i=0;i<v.size();i++) {
                    if (abs(v[i])%2==0) iterasion2=i;
                }
                cout<<" масив 3: ";
                if (iterasion2!=-1) {
                    for(int i = 0; i < v.size() - 1; i++) {
                        if (iterasion2 != i) {
                            v3[i] = v[i];
                            cout<<v3[i]<<" ";
                        }
                    }
                }else cout<<"\nВ масиве отсутствуют чётные эллементы"<<endl;
                cout<<endl;
                break;
            }
            case 5: {
                int count=0,yaz,k;
                char v[100];
                cout<<"Введите название города: ";
                cin.ignore();
                cin.getline(v,101);
                cout<<"Выберите язык слова(Русский-1,Аглийский-2): ";
                cin>>yaz;
                for(int i = 0;v[i]!='\0';i++) count++;
                if (yaz==1) {
                    if(count%4==0) {
                        cout<<"Чётное\n";
                    }else cout<<"Нечётное\n";
                }else {
                    if(count%2==0) {
                        cout<<"Чётное\n";
                    }else cout<<"Нечётное\n";
                }
            }
            case 6: {
                int count1=0,count2=0;
                char v1[100];
                cout<<"Введите фамилию 1: ";
                cin.ignore();
                cin.getline(v1,101);
                for(int i = 0;v1[i]!='\0';i++) count1++;
                char v2[100];
                cout<<"Введите фамилию 2: ";
                cin.getline(v2,101);
                for(int i = 0;v2[i]!='\0';i++) count2++;
                if(count1>count2)cout<<"Фамилия 1 длинее\n";
                if(count1<count2)cout<<"Фамилия 2 длинее\n";
                if(count2==count1)cout<<"Длины фамилий одинаковы\n";
            }
            case 7: {
                int count1=0,count2=0,count3=0;
                char v1[100];
                cout<<"Введите название 1-го города: ";
                cin.ignore();
                cin.getline(v1,101);
                for(int i = 0;v1[i]!='\0';i++) count1++;
                char v2[100];
                cout<<"Введите название 2-го города: ";
                cin.getline(v2,101);
                for(int i = 0;v2[i]!='\0';i++) count2++;
                char v3[100];
                cout<<"Введите название 3-го города: ";
                cin.getline(v3,101);
                for(int i = 0;v3[i]!='\0';i++) count3++;
                if (count1 >= count2 && count1 >= count3) {
                    cout << "Самое длинное название: " << v1 << endl;
                    if (count1 == count2) cout << "Такую же длину имеет города сназванием  " << v2 << endl;
                    if (count1 == count3) cout << "Такую же длину имеет города сназванием  " << v3 << endl;
                } else if (count2 >= count1 && count2 >= count3) {
                    cout << "Самое длинное название: " << v2 << endl;
                    if (count2 == count1) cout << "Такую же длину имеет города сназванием " << v1 << endl;
                    if (count2 == count3) cout << "Такую же длину имеет города сназванием " << v3 << endl;
                } else {
                    cout << "Самое длинное название: " << v3 << endl;
                    if (count3 == count1) cout << "Такую же длину имеет города сназванием " << v1 <<  endl;
                    if (count3 == count2) cout << "Такую же длину имеет города сназванием " << v2 <<  endl;
                }

                if (count1 <= count2 && count1 <= count3) {
                    cout << "Самое короткое название: " << v1 << endl;
                    if (count1 == count2) cout << "Такую же длину имеет города сназванием " << v2 << endl;
                    if (count1 == count3) cout << "Такую же длину имеет города сназванием " << v3 << endl;
                } else if (count2 <= count1 && count2 <= count3) {
                    cout << "Самое короткое название: " << v2 << endl;
                    if (count2 == count1) cout << "Такую же длину имеет города сназванием " << v1 << endl;
                    if (count2 == count3) cout << "Такую же длину имеет города сназванием " << v3 << endl;
                } else {
                    cout << "Самое короткое название: " << v3 << endl;
                    if (count3 == count1) cout << "Такую же длину имеет города сназванием " << v1 << endl;
                    if (count3 == count2) cout << "Такую же длину имеет города сназванием " << v2 << endl;
                }

            }
            case 8: {
                int m,n,yaz;
                char v1[100];
                cout<<"Введите слово: ";
                cin.ignore();
                cin.getline(v1,101);
                cout<<"Введите m и n(n>m):";
                cin>>m>>n;
                cout<<"Выберите язык слова(Русский-1,Аглийский-2): ";
                cin>>yaz;
                if(yaz==1) {
                    for(int i = 2*m-2;i<2*n;i++) cout<<v1[i];
                }
                if(yaz==2) {
                    for(int i = m-1;i<n;i++) cout<<v1[i];
                }
                cout<<endl;
            }
            case 9: {
                int yaz,count=0;
                char v[100];
                cout<<"Введите слово: ";
                cin.ignore();
                cin.getline(v,101);
                for(int i = 0;v[i]!='\0';i++) count++;
                cout<<"Выберите язык слова(Русский-1,Аглийский-2): ";
                cin>>yaz;
                if(yaz==1) {
                    for(int i =0; i<(count/2);i++) cout<<"*";
                    for(int i = 0;v[i]!='\0';i++) cout<<v[i];
                    for(int i =0; i<(count/2);i++) cout<<"*";
                }
                if(yaz==2) {
                    cout<<"2";
                    for(int i =0; i<(count);i++) cout<<"*";
                    for(int i = 0;v[i]!='\0';i++) cout<<v[i];
                    for(int i =0; i<(count);i++) cout<<"*";
                }
                cout<<endl;
            }
            case 10: {
                int count = 0, countA=0,yaz;
                char v[100];
                cout << "Введите предложение: ";
                cin.ignore();
                cin.getline(v, 100);
                for(int i = 0;v[i]!='\0';i++) {
                    if (v[i]!=' ') count++;
                }
                for (int i = 0; v[i] != '\0'; i++) {
                    if (v[i] == 'a'||v[i] == 'A'||v[i] == '\xD0' && v[i+1] == '\xB0'||v[i] == '\xD0' && v[i+1] == '\x90') {
                        countA++;
                    }
                }
                cout<<"Выберите язык слова(Русский-1,Аглийский-2): ";
                cin>>yaz;
                if (yaz==1) {
                    cout<<(double(countA/double(count/2)))*100;
                }
                if(yaz==2) {
                    cout<<(double(countA/double(count)))*100;
                }
                cout<<endl;

            }
            case 11: {
                cout<<"Введите слово на которое хотите заменить:";
                string can;
                cin>>can;
                cout<<can<<" you "<< can<< " a "<< can<< " as a canner "<< can<<" "<< can<< " a "<< can<<"?"<<endl;
            }
        }
    }
return 0;
}
