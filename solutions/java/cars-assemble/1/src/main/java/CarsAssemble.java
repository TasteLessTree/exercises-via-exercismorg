public class CarsAssemble {
    private static final int carsInHour = 221;
    
    public double productionRatePerHour(int speed) {
        if (speed >= 1 && speed <= 4) {
            return speed * carsInHour;
        } else if (speed >= 5 && speed <= 8) {
            return speed * carsInHour * 0.90;
        } else if (speed >= 9 && speed < 10) {
            return speed * carsInHour * 0.80;
        } else {
            return speed * carsInHour * 0.77;
        }
    }

    public int workingItemsPerMinute(int speed) {
        return (int) productionRatePerHour(speed) / 60;
    }
}
