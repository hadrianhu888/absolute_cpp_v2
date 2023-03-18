/**
 * @file gram_schmidt.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void normalize(vector<double>& v);
double dotProduct(const vector<double>& v1, const vector<double>& v2);
void subtractProjection(vector<double>& v1, const vector<double>& v2);

void gramSchmidt(vector<vector<double>>& vectors)
{
    int numVectors = vectors.size();
    for (int i = 0; i < numVectors; i++)
    {
        normalize(vectors[i]);
        for (int j = i + 1; j < numVectors; j++)
        {
            subtractProjection(vectors[j], vectors[i]);
        }
    }
}

void normalize(vector<double>& v)
{
    double length = 0;
    for (double x : v)
    {
        length += x * x;
    }
    length = sqrt(length);
    for (double& x : v)
    {
        x /= length;
    }
}

double dotProduct(const vector<double>& v1, const vector<double>& v2)
{
    double result = 0;
    int size = v1.size();
    for (int i = 0; i < size; i++)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

void subtractProjection(vector<double>& v1, const vector<double>& v2)
{
    double projection = dotProduct(v1, v2);
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] -= projection * v2[i];
    }
}

int main()
{
    vector<vector<double>> vectors = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    gramSchmidt(vectors);
    for (int i = 0; i < vectors.size(); i++)
    {
        cout << "v" << i + 1 << ": ";
        for (int j = 0; j < vectors[i].size(); j++)
        {
            cout << vectors[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
