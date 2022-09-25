#include "point.h"

bool intersect(Point p1, Point p2, Point q1, Point q2, Point& x) {
    Fraction t, u;
    Point r = p2 - p1;
    Point s = q2 - q1;
    Point v = q1 - p1;
    Fraction distance = r * s;

    if (distance != 0) {
        t = (v * s) / (distance);
        u = (v * r) / (distance);

        if ((t >= 0 && t <= 1) && (u >= 0 && u <= 1)) {
            x = p1 + r * t;
            return true;
        }
    }
    return false;
}

bool isInsidePolygon(Point dart, Point corner, Point (&polygons)[100][20], int32_t nVerticies, int32_t polygonIndex) {
    int32_t windingNumber = 0;
    Fraction zero;
    Point
            belowDart(dart.getX(), zero),
            aboveDart(dart.getX(), corner.getY()),
            leftOfDart(zero, dart.getY()),
            rightOfDart(corner.getX(), dart.getY()),
            x, z1, z2;

    for (int32_t i = 0; i < nVerticies; i++) {
        if (i == nVerticies - 1) {
            if (intersect(belowDart, aboveDart, polygons[polygonIndex][i], polygons[polygonIndex][0], x)) {
                z1 = x - dart;
                z2 = polygons[polygonIndex][0] - polygons[polygonIndex][i];

                if (z1.getY() * z2.getX() < 0) {
                    windingNumber += 1;
                }
                else {
                    windingNumber -= 1;
                }
            }

            if (intersect(leftOfDart, rightOfDart, polygons[polygonIndex][i], polygons[polygonIndex][0], x)) {
                z1 = x - dart;
                z2 = polygons[polygonIndex][0] - polygons[polygonIndex][i];

                if (z1.getX() * z2.getY() > 0) {
                    windingNumber += 1;
                }
                else {
                    windingNumber -= 1;

                }
            }
        }else {
            if (intersect(belowDart, aboveDart, polygons[polygonIndex][i], polygons[polygonIndex][i + 1], x)) {
                z1 = x - dart;
                z2 = polygons[polygonIndex][i + 1] - polygons[polygonIndex][i];

                if (z1.getY() * z2.getX() < 0) {
                    windingNumber += 1;
                } else {
                    windingNumber -= 1;
                }
            }

            if (intersect(leftOfDart, rightOfDart, polygons[polygonIndex][i], polygons[polygonIndex][i + 1], x)) {
                z1 = x - dart;
                z2 = polygons[polygonIndex][i + 1] - polygons[polygonIndex][i];

                if (z1.getX() * z2.getY() > 0) {
                    windingNumber += 1;
                } else {
                    windingNumber -= 1;

                }
            }
        }
    }

    if (windingNumber == 0) {
        return false;
    }
    else {
        return true;
    }

}

//Calculate the area of a given polygon from an array
Fraction areaOfPolygon(Point (&polygons)[100][20], int32_t poly, int32_t vert) {
    Fraction area;

    for (int32_t i = 0; i < vert; i++) {
        int j = (i + 1) % vert;
        area = area + polygons[poly][i] * polygons[poly][j];

    }
    return area / 2;
}


int main() {
    //Initialize variables
    int32_t
            nPolygon,
            nVerticies[100],
            nDarts;
    Fraction
            score,
            boardArea;
    Point
            board,
            dart,
            polygons[100][20];
    bool
        ifDartDuplicate[10][100];

    //input
    std::cin >> board;
    boardArea = board.getX() * board.getY();// Used to calculate the area of the dart board
    std::cin >> nPolygon;
    if (nPolygon > 0 && nPolygon <= 100)
        for (int i = 0; i < nPolygon; i++) {
            std::cin >> nVerticies[i];
            if (nVerticies[i] >= 3 && nVerticies[i] <= 20)
                for (int32_t k = 0; k < nVerticies[i]; k++) {
                    std::cin >> polygons[i][k];
                }
            else
                std::cout << "You have entered an invalid number of Verticies.";
            return 1;
        }
    else
        std::cout << "You have entered an invalid number of Polygons.";
        return 1;
    // Number of darts thrown
    std::cin >> nDarts;
    if (nDarts <= 10)
        for (int32_t i = 0; i < nDarts; i++) {
            std::cin >> dart;
            for (int32_t k = 0; k < nPolygon; k++) {
                ifDartDuplicate[i][k] = isInsidePolygon(dart, board, polygons, nVerticies[k], k);
            }
        }

        for (int32_t i = 0; i < nDarts; i++) {
            for (int32_t k = 0; k < sizeof(ifDartDuplicate[i]); k++) {
                int32_t j = i + 1;
                while ( j <  nDarts) {
                    if (ifDartDuplicate[i][k] == ifDartDuplicate[j][k]) {
                        ifDartDuplicate[i][k] = false;
                    }
                    j++;
                }
                if (ifDartDuplicate[i][k]) {
                    score = score + (boardArea/areaOfPolygon(polygons, k, nVerticies[k]));
                }
            }
        }
        std::cout << "Score: " << score << std::endl;
    else
        std::cout << "You have entered an invalid number of Darts.";
        return 1;
    return 0;

}