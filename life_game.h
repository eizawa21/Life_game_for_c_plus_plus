class life_game{
    private:
       const static int Filed_Height = 35; //フィールドの高さを指定している。
       const static int Filed_Width = 55; //フィールドの幅を指定している。
       int cell_cnt; //探索時の、自身と周りのセルの状態をカウントするためのカウンター。
       int arr[Filed_Height][Filed_Width]; //２次元配列を用意する。
       int calc_arr[Filed_Height+2][Filed_Width+2]; //計算用の２次元配列も用意する。+2にしているのは探索時のインデックスエラーを防ぐため。

    public:
       life_game(int cell_density); //コンストラクタ。
       ~life_game(); //デストラクタ、終了時に終了メッセージを表示するだけ。
       int random_numbder_generator(int num); //乱数発生機。
       void set_calc_arr();
       void count_cell();
       int next_generation(int l,int j,int cell_cnt);
       void show_cell();
};