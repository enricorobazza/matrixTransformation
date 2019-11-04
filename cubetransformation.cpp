#include "cubetransformation.h"

#include <QMatrix4x4>

vector<QVector3D> CubeTransformation::Transform(vector<QVector3D>& points)
{
    // moves the cube 10 units backwards,
    // so it can fit in the far / near clipping planes
    auto tz = translationZ(-10);


    return applyTransformation (points, tz);
}


vector<vector<float>> CubeTransformation::translationZ (float z)
{
    return
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, z},
        {0, 0, 0, 1},
    };
}


vector<QVector3D> CubeTransformation::applyTransformation (vector<QVector3D>& pts,
                                                           vector<vector<float>> trans)
{
    vector<QVector3D> outpts (pts.size());

    for (size_t i = 0; i < pts.size(); i++) {
        auto pt = pts[i];

        outpts[i] = QVector3D(
                trans[0][0] * pt.x() + trans[0][1] * pt.y() + trans[0][2] * pt.z() + trans[0][3],
                trans[1][0] * pt.x() + trans[1][1] * pt.y() + trans[1][2] * pt.z() + trans[1][3],
                trans[2][0] * pt.x() + trans[2][1] * pt.y() + trans[2][2] * pt.z() + trans[2][3]
        );
    }

    return outpts;
}
