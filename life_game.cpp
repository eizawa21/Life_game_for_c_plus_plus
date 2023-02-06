#include <iostream>
#include <random>
#include "life_game.h"

using namespace std;

life_game::life_game(int cell_density){ //コンストラクタでオブジェクト生成時に配列を初期化し、乱数発生機で作成した乱数を配列に挿入する。

    cell_cnt = 0;

    for(int i = 0;i < Filed_Height+2;i++){ //計算用に使う２次元配列を初期化している。
        for(int j = 0;j < Filed_Width+2;j++){
            calc_arr[i][j] = 0;
        }
    }
    for(int i = 0;i < Filed_Height;i++){
        for(int j = 0;j < Filed_Width;j++){
            arr[i][j] = random_numbder_generator(cell_density); //乱数発生機で生成した0か1の数値を配列に代入している。
        }
    }
}

life_game::~life_game(){ //プログラム終了時に実行されるデストラクタ。
    cout << "END OF GAME!" << endl;
}

int life_game::random_numbder_generator(int num){ //1が出る確率の設定。0-100
    int output_num = 0;

    mt19937 mt{ random_device{}() }; //乱数発生機。標準ライブラリを利用している。メルセンヌツイスターで乱数を発生させる。
    uniform_int_distribution<int> dist(0, 100);

    if(dist(mt) <= num){
        output_num = 1;
    }
    else{
        output_num = 0;
    }
    
    return output_num;

}

void life_game::set_calc_arr(){ //arrからcalc_arrに要素の中身をコピーする。
    for(int i = 0;i < Filed_Height;i++){
        for(int j = 0;j < Filed_Width;j++){
            calc_arr[i+1][j+1] = arr[i][j];
        }
    }
}

void life_game::count_cell(){ //自身を原点として、周囲８マスのセルの状態を探索する関数。

    for(int i = 1; i < Filed_Height+1;i++){

        for (int j  = 1;j < Filed_Width+1; j++){
            for(int y = i-1;y < i+2;y++){
                for(int x = j-1;x < j+2;x++){
                    if(calc_arr[y][x] == 1){
                        cell_cnt += 1;
                    }

                }
            }
         arr[i-1][j-1] = next_generation(i,j,cell_cnt); //２元配列のインデックスと周囲のセルの数を引数にしている。
         cell_cnt = 0;

        }
      
    }
}

int life_game::next_generation(int i,int j,int cell_cnt){ //周辺のセルの状態から次世代のセルの生死判定をおこなう。

    if(calc_arr[i][j] == 1){ //現時点のセルが生きていればこの下のコードが実行される。
        if(cell_cnt == 3 || cell_cnt == 4){ //自身を含めて、周囲のセルが２と３ならそのセルは生存。
            return 1;
        }
        else{
            return 0;
        }        
    }
    else{ //現時点のセルが死んでいるなら、ここから下のコードが実行される。
        if(cell_cnt == 3){ //セルの周囲に生きているセルが３個あれば、セルが誕生する。
            return 1;
        }
        else{ //周囲のセルが３以外ならセルは誕生しない。
            return 0;
        }
    }
}

void life_game::show_cell(){ //受け取った配列を、1=■ 0=□に変換して出力するための関数。
    for(int i = 0;i < Filed_Height;i++){
        for(int j = 0;j < Filed_Width;j++){
            if(arr[i][j] == 0){
                cout << "□ ";
            }
            else{
                cout << "■ ";
            }
        }
        cout << endl;
    }
}
