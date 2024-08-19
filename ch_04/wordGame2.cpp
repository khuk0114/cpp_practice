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
    cout << "���� �ձ� ������ �����մϴ�\n";
    cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�?";
    this->word = "�ƹ���";
}

void wordGame::start() {
    cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�.\n";
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
    this->name = "�ƹ���";
    this->word = "�ܾ�";
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

    wordGame game; //���� ����

    int num; //�ο� ��
    cin >> num; 
    Player* player = new Player[num]; // ���� ��ü �Ҵ�

    for (int i = 0; i < num; i++) {
        cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>>";
        string name;
        cin >> name;
        player[i].set_name(name);
    }

    game.start();

    //game.set_word("�ƹ���");

    int i = 0;
    while (1) {
        cout << player[i % num].get_name() << ">>";
        string word;
        cin >> word;

        player[i % num].set_word(word); //�÷��̾� �ܾ� �����ϱ�

        if (!game.is_right(game.get_word(), player[i % num].get_word())) {
            cout << "Ʋ�Ƚ��ϴ�.";
            break;
        }

        game.set_word(player[i % num].get_word()); //���� ���� �ܾ �÷��̾� �ܾ� ����ֱ�

        i++;
    }

    delete[] player;
    return 0;
}
