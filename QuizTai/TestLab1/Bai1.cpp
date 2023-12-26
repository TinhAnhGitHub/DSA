class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};



void Polynomial::insertTerm(const Term& term) {
    // Iterate through the existing terms to find the correct position based on exponents
    if(term.coeff == 0){
        return;
    }
    SLinkedList<Term>::Iterator it;
    int index = 0;

    for (it = this->terms->begin(); it != this->terms->end(); it++) {
        if (term.exp > (*it).exp) {
            this->terms->add(index, term);
            return;
        } else if (term.exp == (*it).exp) {
            // If exponents are equal, combine the coefficients
            (*it).coeff += term.coeff;

            // If the combined coefficient is zero, remove the term
            if ((*it).coeff == 0.0) {
                this->terms->removeAt(index);
            }

            return;
        }

        index++;
    }

    // If the loop completes, add the term at the end (lowest exponent)
    this->terms->add(term);
}
void Polynomial::insertTerm(double coeff, int exp){
    Term term(coeff, exp);
    return this->insertTerm(term);
}
