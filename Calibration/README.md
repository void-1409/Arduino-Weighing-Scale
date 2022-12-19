## Calibration Instructions
1. For calibration, you will need a **known weight(eg. 1kg)** to calibrate loadcell accordingly.
2. Upload the above code to your arduino and put the known weight on the scale and check weight displayed on serial monitor.
3. Now in order to find your personalized calibration factor, you need to change the value of calibration factor variable in above code.
4. This factor is inversly proportional to weight. So change the factor accordingly until the weight displyed on serial monitor is equal to the known weight.
5. Once both values(i.e. known weight and displayed weight) matches, **copy** this calibration factor to the **Loadcell** file.
