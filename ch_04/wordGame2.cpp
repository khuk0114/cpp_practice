#include <iostream>
#include <string>
using namespace std;

class wordGame {
    string word;
public:
    wordGame();
    void start();
    bool is_right(string word1, string word2);
    void set_word(string word);
    string get_word();
};

wordGame::wordGame() {
    cout << "끝말 잇기 게임을 시작합니다\n";
    cout << "게임에 참가하는 인원은 몇명입니까?";
    this->word = "아버지";
}

void wordGame::start() {
    cout << "시작하는 단어는 아버지입니다.\n";
}

void wordGame::set_word(string word) {
    this->word = word;
}

bool wordGame::is_right(string word1, string word2) {
    if (word1.at(word1.size() - 2) == word2.at(0) && word1.at(word1.size() - 1) == word2.at(1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string wordGame::get_word() {
    return this->word;
}

class Player {
    string name;
    string word;
public:
    Player();
    void set_name(string name);
    void set_word(string word);
    string get_name();
    string get_word();
};

Player::Player() {
    this->name = "아무개";
    this->word = "단어";
}

void Player::set_name(string name) {
    this->name = name;
}

void Player::set_word(string word) {
    this->word = word;
}

string Player::get_name() {
    return this->name;
}

string Player::get_word() {
    return this->word;
}

int main() {

    wordGame game; //게임 시작

    int num; //인원 수
    cin >> num; 
    Player* player = new Player[num]; // 동적 객체 할당

    for (int i = 0; i < num; i++) {
        cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
        string name;
        cin >> name;
        player[i].set_name(name);
    }

    game.start();

    //game.set_word("아버지");

    int i = 0;
    while (1) {
        cout << player[i % num].get_name() << ">>";
        string word;
        cin >> word;

        player[i % num].set_word(word); //플레이어 단어 설정하기

        if (!game.is_right(game.get_word(), player[i % num].get_word())) {
            cout << "틀렸습니다.";
            break;
        }

        game.set_word(player[i % num].get_word()); //현재 게임 단어에 플레이어 단어 집어넣기

        i++;
    }

    delete[] player;
    return 0;
}
