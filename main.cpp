#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

bool isnum;
bool isNum(string s){
    isnum = true;
    for(int i = 0; i < s.size(); i++){
        if(!isdigit(s[i])) isnum = false;
    }
    if(isnum){
        return true;
    } else {
        return false;
    }
}

int main(){
reinput_peopleNum:
    cout << "人数を入力" << endl;
    string peopleNum;
    int peopleNum_stoi;
    cin >> peopleNum;
    if(!isNum(peopleNum)){
        cout << "無効な入力" << endl;
        goto reinput_peopleNum;
    }
    peopleNum_stoi = stoi(peopleNum);
    vector<int> seatNum(peopleNum_stoi);
    for(int i = 0; i < peopleNum_stoi; i++){
        seatNum[i] = -1;
    }
    //setRandom
    random_device rnd;
    int rndNum;
    for(int i = 0; i < peopleNum_stoi; i++){
        retry:
        rndNum = rnd() % peopleNum_stoi + 1;
        for(int j = 0; j < peopleNum_stoi; j++){
            if(seatNum[j] == rndNum) goto retry;
        }
        seatNum[i] = rndNum;
    }
    //config
    string pos, val;
    int pos_stoi, val_stoi;
    int counter = 0;
    cout << "固定席の設定（endで終了）" << endl;
    cout << "1~人数までの数字で席を指定する" << endl;
    cout << "指定する際の席の番号" << endl;
    for(int i = 0; i < peopleNum_stoi; i++){
        cout << '[';
        if((i+1) / 10 == 0) cout << ' ';
        cout << i+1 << ']';
        if(counter == 5){
            cout << endl;
            counter = -1;
        }
        counter++;
    }
    cout << endl;
    while(1){
        counter = 0;
reinput_pos:
        cout << "席を指定" << endl;
        cin >> pos;
        if(pos == "end"){
            for(int i = 0; i < 20; i++){
                cout << endl;
            }
            break;
        }
        if(!isNum(pos)){
            cout << "無効な入力" << endl;
            goto reinput_pos;
        }
        pos_stoi = stoi(pos);
        if(pos_stoi > peopleNum_stoi){
            cout << "無効な入力" << endl;
            goto reinput_pos;
        }
reinput_val:
        cout << "出席番号を入力" << endl;
        cin >> val;
        if(!isNum(val)){
            cout << "無効な入力" << endl;
            goto reinput_val;
        }
        val_stoi = stoi(val);
        if(val_stoi > peopleNum_stoi){
            cout << "無効な入力" << endl;
            goto reinput_val;
        }
        seatNum[pos_stoi-1] = val_stoi;
        cout << "プレビュー" << endl;
        for(int i = 0; i < peopleNum_stoi; i++){
            cout << '[';
            if(seatNum[i] / 10 == 0 && seatNum[i] != -1) cout << 0;
            cout << seatNum[i] << ']';
            if(counter == 5){
                cout << endl;
                counter = -1;
            }
            counter++;
        }
        cout << endl;
    }
    //do
    counter = 0;
    cout << "ARE YOU READY? (pless Enter)" << endl;
    while(getchar() != '\n');
    while(getchar() != '\n');
    for(int i = 3; i >= 1; i--){
        cout << i << endl;
        sleep(1);
    }
    cout << "GO!!!" << endl << endl;
    sleep(1);
    cout << "-------黒板--------" << endl << endl;
    for(int i = 0; i < peopleNum_stoi; i++){
        cout << '[';
        if(seatNum[i] / 10 == 0) cout << 0;
        cout << seatNum[i] << ']';
        if(counter == 5){
            cout << endl;
            counter = -1;
            sleep(1);
        }
        counter++;
    }
    cout << endl << endl;
    cout << "FINISH!!!!" << endl << endl;
    cout << "endで終了" << endl;
    string end;
    while(1){
        cin >> end;
        if(end == "end") break;
    }
}
