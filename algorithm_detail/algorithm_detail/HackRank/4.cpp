#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

int longest(const string& str1, const string& str2)
{
    int m = str1.size(), n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void counterspell(Spell *spell) 
{
    if (Fireball* fb = dynamic_cast<Fireball*>(spell))
    {
        fb->revealFirepower();
    }
    else if (Frostbite* frost = dynamic_cast<Frostbite*>(spell))
    {
        frost->revealFrostpower();
    }
    else if (Waterbolt* wb = dynamic_cast<Waterbolt*>(spell))
    {
        wb->revealWaterpower();
    }
    else if (Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell))
    {
        ts->revealThunderpower();
    }
    else
    {
        string spellName = spell->revealScrollName();
        string journal = SpellJournal::journal;
        cout << longest(spellName, journal) << "\n";        
     }
}

/*
* 내부에 구현
void counterspell(Spell *spell) {
    if (Fireball* fb = dynamic_cast<Fireball*>(spell)) {
        fb->revealFirepower();
    } else if (Frostbite* frost = dynamic_cast<Frostbite*>(spell)) {
        frost->revealFrostpower();
    } else if (Waterbolt* wb = dynamic_cast<Waterbolt*>(spell)) {
        wb->revealWaterpower();
    } else if (Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)) {
        ts->revealThunderpower();
    } else {
        // 여기서부터 longest 함수 로직을 counterspell 내부에 직접 구현합니다.
        string spellName = spell->revealScrollName();
        string journal = SpellJournal::journal;
        int m = spellName.size(), n = journal.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (spellName[i - 1] == journal[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[m][n] << "\n"; // LCS 길이 출력
    }
}
*/

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}