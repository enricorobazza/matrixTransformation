#ifndef CUBETRANSFORMATION_H
#define CUBETRANSFORMATION_H

#include <QVector3D>
#include <vector>
using namespace std;

class CubeTransformation
{
public:
    static vector<QVector3D> Transform(vector<QVector3D>&);

private:
    // returns the transformation matrix to a translation alongside "Z"
    static vector<vector<float>> translationZ (float);

    static vector<QVector3D> applyTransformation (vector<QVector3D>&, vector<vector<float>>);
};

#endif // CUBETRANSFORMATION_H
