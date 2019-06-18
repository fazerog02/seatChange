#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;


// 文字列が数字かどうか判定する
bool IsNumber(string s){
    for(int i = 0; i < s.size(); i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}


int main(){
    string num_of_people_str = "default";
    int num_of_people;
    while(!IsNumber(num_of_people_str)){
        cout << "人数を入力してください" << endl;
        cout << ">>> ";
        cin >> num_of_people_str;  // 文字を入力されたときのためにstringで受けておく
    }
    num_of_people = stoi(num_of_people_str);

    // 座席表の出席番号を-1で初期化しておく
    vector<int> seating_chart(num_of_people);
    for(int i = 0; i < num_of_people; i++){
        seating_chart[i] = -1;
    }

    // 限定ランダムの設定
    cout << "限定ランダムの設定(目が悪い人など用)" << endl;
    // 席の番号表を表示する
    cout << "席の番号" << endl;
    for(int i = 1; i <= num_of_people; i++){
        printf("%c%2d%c ", '[', i, ']');
        if(i % 6 == 0) cout << endl;  // 6個ずつで改行する
    }
    cout << endl;

    // 限定でランダムに選ぶ席を指定する
    string selected_position_str = "default";
    int selected_position;
    vector<int> selected_position_list;
    cout << "限定でランダムに選ぶ席を指定してください[endで終了]" << endl;
    while(1){
        cout << "席番号を入力してください" << endl;
        cout << ">>> ";
        cin >> selected_position_str;  // 文字を入力されたときのためにstringで受けておく
        if(selected_position_str == "end") break;
        if(!IsNumber(selected_position_str)) continue;

        selected_position = stoi(selected_position_str);
        selected_position_list.push_back(selected_position);
    }
    system("clear");

    // 限定でランダムに選ぶ出席番号を指定する
    string selected_seat_num_str = "default";
    int selected_seat_num;
    vector<int> selected_seat_num_list;
    cout << "限定でランダムに選ぶ出席番号を指定してください[endで終了]" << endl;
    while(1){
        cout << "出席番号を入力してください" << endl;
        cout << ">>> ";
        cin >> selected_seat_num_str;  // 文字を入力されたときのためにstringで受けておく
        if(selected_seat_num_str == "end") break;
        if(!IsNumber(selected_seat_num_str)) continue;

        selected_seat_num = stoi(selected_seat_num_str);
        selected_seat_num_list.push_back(selected_seat_num);
    }
    system("clear");

    // 限定ランダムの座席を先に決める
    random_device random;
    int random_number;
    bool does_exist;
    int random_seat_position;
    // 限定ランダムの各出席番号に対応する座席を決める
    for(int i = 0; i < selected_seat_num_list.size(); i++){
        does_exist = true;
        while(does_exist){
            does_exist = false;
            // 指定された座席からランダムで選ぶ
            random_number = random() % selected_position_list.size();
            random_seat_position = selected_position_list[random_number]-1;

            if(seating_chart[random_seat_position] != -1) does_exist = true;  // すでに選ばれているかどうか確認する
        }
        seating_chart[random_seat_position] = selected_seat_num_list[i];  // 座席表に限定ランダムの結果を代入する
    }

    // 座席をランダムに決める
    for(int i = 0; i < num_of_people; i++){
        if(seating_chart[i] != -1) continue;  // すでに決めてあったらスキップする
        does_exist = true;
        while(does_exist){
            does_exist = false;
            random_number = (random() % num_of_people) + 1;  // ランダムで出席番号を一つ選ぶ
            // 選んだ出席番号がすでに使われているかどうか確かめる
            for(int j = 0; j < num_of_people; j++){
                if(seating_chart[j] == random_number) does_exist = true;
            }
        }
        seating_chart[i] = random_number;  // 座席表にランダムの結果を代入する
    }

    // 座席表を表示する
    cout << "Enterを押してスタート" << endl;
    // Enterの入力待ち
    while(getchar() != '\n');
    while(getchar() != '\n');

    // ３秒カウントする
    for(int i = 3; i >= 1; i--){
        cout << i << endl;
        sleep(1);
    }
    cout << "GO!" << endl << endl;
    sleep(1);

    // 表を表示する
    cout << "-------黒板--------" << endl << endl;
    for(int i = 0; i < num_of_people; i++){
        printf("%c%2d%c ", '[', seating_chart[i], ']');
        if((i+1) % 6 == 0) cout << endl;  // 6個ずつで改行する
    }
    cout << endl << endl;

    cout << "FINISH!" << endl << endl;
    cout << "endで終了" << endl;
    string end;
    while(1){
        // endの入力待ち
        cin >> end;
        if(end == "end") break;
    }

    return 0;
}
