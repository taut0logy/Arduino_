#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ert.cpp"
#include <vector>
#include <string>
#include <iostream>

std::vector<int> extract(std::string s) {
    std::vector<int> coeff(101, 0);  // Changed to 101 to accommodate coefficients from 0 to 100
    double esp1 = 0, esp2 = 0;
    int i = 0;

    while (i < s.size()) {
        int pow = 0;
        double coe = 1.0;
        std::string p = "";
        std::string c = "";

        if (s[i] == '=') {
            i++;
        }

        while (i < s.size() && s[i] != '=' && s[i] != 'x') {
            c += s[i];
            i++;
        }

        if (s[i] == '=')
            esp1 = std::stod(c);
        else
            esp2 = std::stod(c);

        while (i < s.size() && (s[i] == 'x' || s[i] == '^')) {
            if (s[i] == 'x') {
                i++;
                if (s[i] != '^') {
                    pow = 1;
                }
            }
            if (s[i] == '^') {
                i++;
                p = "";
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    p += s[i];
                    i++;
                }
                pow = std::stoi(p);
            }

            if (s[i] == '+' || s[i] == '-' || i == s.size()) {
                if (c == "" || c == "+" || c == "-")
                    c += '1';
                coe = std::stod(c);
                coeff[pow] = static_cast<int>(coe);
            }

            if (s[i] == '+' || s[i] == '-') {
                if (s[i] == '-')
                    coe = -coe;
                i++;
            }
        }
    }

    coeff[0] = static_cast<int>(esp2 - esp1);
    return coeff;
}

int main() {
    std::string poly = "25x^3-21x^2+1x^1=10";
    std::vector<int> coefficients = extract(poly);

    for (int i = 0; i < coefficients.size(); i++) {
        if (coefficients[i] != 0) {
            std::cout << "Coefficient of x^" << i << ": " << coefficients[i] << std::endl;
        }
    }

    return 0;
}
