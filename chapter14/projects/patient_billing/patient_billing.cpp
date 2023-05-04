/**
 * @file patient_billing.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Person
{
protected:
    string name;
    string address;
    string telephone;
    Person* person;
public:
    Person(const string& name, const string& address, const string& telephone)
        : name(name), address(address), telephone(telephone) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    const string& getAddress() const { return address; }
    void setAddress(const string& address) { this->address = address; }

    const string& getTelephone() const { return telephone; }
    void setTelephone(const string& telephone) { this->telephone = telephone; }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
    }
    ~Person() {}
};

class Doctor:public Person
{
protected:
    string specialty;
    double fee;
    Doctor* doctor;
public:
    Doctor(const string& name, const string& address, const string& telephone, const string& specialty, double fee)
        : Person(name, address, telephone), specialty(specialty), fee(fee) {}

    const string& getSpecialty() const { return specialty; }
    void setSpecialty(const string& specialty) { this->specialty = specialty; }

    double getFee() const { return fee; }
    void setFee(double fee) { this->fee = fee; }

    virtual void print() const override {
        Person::print();
        cout << "Specialty: " << specialty << endl;
        cout << "Fee: " << fee << endl;
    }
    ~Doctor() {}
};

class Billing:public Person
{
protected:
    string patientAccountNumber;
    double charges;
    double payments;
    double credits;
    Billing* billing;
public:
    Billing(const string& name, const string& address, const string& telephone, const string& patientAccountNumber, double charges, double payments, double credits)
        : Person(name, address, telephone), patientAccountNumber(patientAccountNumber), charges(charges), payments(payments), credits(credits) {}

    const string& getPatientAccountNumber() const { return patientAccountNumber; }
    void setPatientAccountNumber(const string& patientAccountNumber) { this->patientAccountNumber = patientAccountNumber; }

    double getCharges() const { return charges; }
    void setCharges(double charges) { this->charges = charges; }

    double getPayments() const { return payments; }
    void setPayments(double payments) { this->payments = payments; }

    double getCredits() const { return credits; }
    void setCredits(double credits) { this->credits = credits; }

    virtual void print() const override {
        Person::print();
        cout << "Patient Account Number: " << patientAccountNumber << endl;
        cout << "Charges: " << charges << endl;
        cout << "Payments: " << payments << endl;
        cout << "Credits: " << credits << endl;
    }

    ~Billing() {}
};

class Patient:public Person
{
protected:
    string patientAccountNumber;
    Doctor* doctor;
    Patient* billing;
public:
    Patient(const string& name, const string& address, const string& telephone, const string& patientAccountNumber, Doctor* doctor)
        : Person(name, address, telephone), patientAccountNumber(patientAccountNumber), doctor(doctor) {}

    const string& getPatientAccountNumber() const { return patientAccountNumber; }
    void setPatientAccountNumber(const string& patientAccountNumber) { this->patientAccountNumber = patientAccountNumber; }

    Doctor* getDoctor() const { return doctor; }
    void setDoctor(Doctor* doctor) { this->doctor = doctor; }

    Patient* getBilling() const { return billing; }
    void setBilling(Patient* billing) { this->billing = billing; }

    virtual void print() const override {
        Person::print();
        cout << "Patient Account Number: " << patientAccountNumber << endl;
        cout << "Doctor: " << doctor->getName() << endl;
    }
    ~Patient() {}
};

int main(int argc, char const *argv[])
{
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Billing> billings;

    Doctor doc1("John", "123 Main St.", "555-1234", "Heart", 100.0);
    Doctor doc2("Mary", "123 Main St.", "555-1234", "Lungs", 200.0);

    Patient pat1("Tom", "234 Elm St.", "555-2345", "A123", &doc1);
    Patient pat2("Jane", "234 Elm St.", "555-2345", "B456", &doc2);

    Billing bill1("Tom", "234 Elm St.", "555-2345", "A123", 100.0, 25.0, 10.0);
    Billing bill2("Jane", "234 Elm St.", "555-2345", "B456", 200.0, 50.0, 20.0);

    doctors.push_back(doc1);
    doctors.push_back(doc2);

    patients.push_back(pat1);
    patients.push_back(pat2);

    billings.push_back(bill1);
    billings.push_back(bill2);

    for (auto& doctor : doctors)
    {
        doctor.print();
        cout << endl;
    }

    for (auto& patient : patients)
    {
        patient.print();
        cout << endl;
    }

    for (auto& billing : billings)
    {
        billing.print();
        cout << endl;
    }

    return 0;
}
