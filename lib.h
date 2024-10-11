#include <string>


class BaseVehicle
{
protected:
   std::string make;
   std::string model;

public:
   int type;
   BaseVehicle(int type, std::string make, std::string model);
   virtual ~BaseVehicle() = default;
   virtual std::string GetData() const = 0;
   virtual void PrintData() const = 0;

   void SetMake(std::string make_);
   void SetModel(std::string model_);
};


class Garage
{
private:
   BaseVehicle** vehicles;
   int length;

public:
   Garage();
   Garage(const Garage& garage);
   ~Garage();

   void Add(BaseVehicle* vehicle);
   void Del(int index);
   void Save(std::string filename);
   void Load(std::string filename);
   BaseVehicle* GetVehicle(int index);
   int GetCountVehicles();
};


class Car : public BaseVehicle
{
private:
   float engineSize;
   std::string color;
   std::string gearboxType;

public:
   Car();
   Car(std::string make, std::string model, float engineSize, std::string color, std::string gearboxType);
   Car(const Car& car);
   virtual ~Car();
   virtual std::string GetData() const override;
   virtual void PrintData() const override;

   void SetEngineSize(float engineSize_);
   void SetColor(std::string color_);
   void SetGearboxType(std::string gearboxType_);
};


class Motorcycle : public BaseVehicle
{
private:
   float engineSize;
   float enginePower;
   std::string motorcycleType;

public:
   Motorcycle();
   Motorcycle(std::string make, std::string model, float engineSize, float enginePower, std::string motorcycleType);
   Motorcycle(const Motorcycle& motorcycle);
   virtual ~Motorcycle();
   virtual std::string GetData() const override;
   virtual void PrintData() const override;
   
   void SetEngineSize(float engineSize_);
   void SetEnginePower(float enginePower_);
   void SetMotorcycleType(std::string motorcycleType_);
};


class Bus : public BaseVehicle
{
private:
   int seatsPassenger;
   int seatsTotal;
   std::string destination;

public:
   Bus();
   Bus(std::string make, std::string model, int seatsPassenger, int seatsTotal, std::string destination);
   Bus(const Bus& bus);
   virtual ~Bus();
   virtual std::string GetData() const override;
   virtual void PrintData() const override;

   void SetSeatsPassenger(int seatsPassenger_);
   void SetSeatsTotal(int seatsTotal_);
   void SetDestination(std::string destination_);
};