struct Distance {
    int feet;
    float inches;
};
truct Distance {
    int feet;
    float inches;
};
Distance maxDistance(Distance d1, Distance d2);

Distance maxDistance(Distance d1, Distance d2) {
    float len1 = d1.feet + d1.inches / 12.0;
    float len2 = d2.feet + d2.inches / 12.0;
    return (len1 > len2) ? d1 : d2;
}
