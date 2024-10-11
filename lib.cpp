#include "lib.h"
#include <iostream>
#include <fstream>
#include <format>


Garage::Garage()
   : vehicles(nullptr)
   , length(0)
{
   std::cout << "Class Garage() created!" << std::endl;
}


Garage::Garage(const Garage& garage)
   : vehicles(nullptr)
{
   std::cout << "Class Garage() created!" << std::endl;
}


Garage::~Garage()
{
   std::cout << "Class Garage() deleted!" << std::endl;
}


void Garage::Add(BaseVehicle* vehicle)
{
   BaseVehicle** vehiclesNew = new BaseVehicle*[length + 1];
   for (unsigned long long i = 0; i < length; i++)
   {
      vehiclesNew[i] = vehicles[i];
   }
   vehiclesNew[length] = vehicle;
   vehicles = vehiclesNew;
   vehiclesNew = nullptr;
   length++;
}


void Garage::Del(int index)
{
   BaseVehicle** vehiclesNew = new BaseVehicle*[length - 1];
   for (int i = 0, j = 0; i < length; i++)
   {
      if (i != index)
      {
         *(vehiclesNew + j++) = vehicles[i];
      }
      else
      {
         delete[] vehicles[i];
      }
   }
   vehicles = vehiclesNew;
   vehiclesNew = nullptr;
   length--;
}


void Garage::Load(std::string filename)
{
   std::ifstream file(filename);
   file >> length;
   vehicles = new BaseVehicle*[length];
   for (int i = 0; i < length; i++)
   {
      BaseVehicle* vehicleNew = nullptr;
      int vehicleType;
      std::string make;
      std::string model;
      file >> vehicleType >> make >> model;
      switch (vehicleType)
      {
         case 0:
         {
            float engineSize;
            std::string color;
            std::string gearboxType;
            file >> engineSize >> color >> gearboxType;
            vehicleNew = new Car(make, model, engineSize, color, gearboxType);
            break;
         }
         case 1:
         {
            float engineSize;
            float enginePower;
            std::string motorcycleType;
            file >> engineSize >> enginePower >> motorcycleType;
            vehicleNew = new Motorcycle(make, model, engineSize, enginePower, motorcycleType);
            break;
         }
         case 2:
         {
            int seatsPassenger;
            int seatsTotal;
            std::string destination;
            file >> seatsPassenger >> seatsTotal >> destination;
            vehicleNew = new Bus(make, model, seatsPassenger, seatsTotal, destination);
            break;
         }
      }
      vehicles[i] = vehicleNew;
   }
   file.close();
}


void Garage::Save(std::string filename)
{
   std::ofstream file(filename);
   file << length << std::endl;
   for (unsigned long long i = 0; i < length; i++)
   {
      BaseVehicle* vehicle = vehicles[i];
      file << vehicle->GetData() << std::endl;
   }
   file.close();
}


BaseVehicle* Garage::GetVehicle(int index)
{
   return *(vehicles + index);
}


int Garage::GetCountVehicles()
{
   return length;
}


BaseVehicle::BaseVehicle(int type, std::string make, std::string model)
   : type(type)
   , make(make)
   , model(model)
{}


void BaseVehicle::SetMake(std::string make_)
{
   make = make_;
}


void BaseVehicle::SetModel(std::string model_)
{
   model = model_;
}


Car::Car()
   : BaseVehicle{ 0, "bmw", "auto" }
   , engineSize(1.f)
   , color("red")
   , gearboxType("automated")
{
   std::cout << "Class Car() created!" << std::endl;
}


Car::Car(std::string make, std::string model, float engineSize, std::string color, std::string gearboxType)
   : BaseVehicle{ 0, make, model}
   , engineSize(engineSize)
   , color(color)
   , gearboxType(gearboxType)
{
   std::cout << "Class Car() created!" << std::endl;
}


Car::Car(const Car& car)
   : BaseVehicle{ 0, car.make, car.model}
   , engineSize(car.engineSize)
   , color(car.color)
   , gearboxType(car.gearboxType)
{
   std::cout << "Class Car() created!" << std::endl;
}


Car::~Car()
{
   std::cout << "Class Car() deleted!" << std::endl;
}


std::string Car::GetData() const
{
   return std::format("0\n{}\n{}\n{}\n{}\n{}", make, model, engineSize, color, gearboxType);
}


void Car::PrintData() const
{
   std::cout << "type: car, model: " << make << ", model: " << model << ", engine size: "
      << engineSize << ", color: " << color << ", gearbox type: " << gearboxType << std::endl;
}


void Car::SetEngineSize(float engineSize_)
{
   engineSize = engineSize_;
}


void Car::SetColor(std::string color_)
{
   color = color_;
}


void Car::SetGearboxType(std::string gearboxType_)
{
   gearboxType = gearboxType_;
}


Motorcycle::Motorcycle()
   : BaseVehicle{ 1, "bmw", "motorcycle" }
   , engineSize(1.f)
   , enginePower(1.f)
   , motorcycleType("sport")
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Motorcycle::Motorcycle(std::string make, std::string model, float engineSize, float enginePower, std::string motorcycleType)
   : BaseVehicle{ 1, make, model}
   , engineSize(engineSize)
   , enginePower(enginePower)
   , motorcycleType(motorcycleType)
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Motorcycle::Motorcycle(const Motorcycle& motorcycle)
   : BaseVehicle{ 1, motorcycle.make, motorcycle.model}
   , engineSize(motorcycle.engineSize)
   , enginePower(motorcycle.enginePower)
   , motorcycleType(motorcycle.motorcycleType)
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Motorcycle::~Motorcycle()
{
   std::cout << "Class Motorcycle() deleted!" << std::endl;
}


std::string Motorcycle::GetData() const
{
   return std::format("1\n{}\n{}\n{}\n{}\n{}", make, model, engineSize, enginePower, motorcycleType);
}


void Motorcycle::PrintData() const
{
   std::cout << "type: motorcycle, model: " << make << ", model: " << model << ", engine size: "
      << engineSize << ", engine power: " << enginePower << ", motorcycle type: " << motorcycleType << std::endl;
}


void Motorcycle::SetEngineSize(float engineSize_)
{
   engineSize = engineSize_;
}


void Motorcycle::SetEnginePower(float enginePower_)
{
   enginePower = enginePower_;
}


void Motorcycle::SetMotorcycleType(std::string motorcycleType_)
{
   motorcycleType = motorcycleType_;
}


Bus::Bus()
   : BaseVehicle{ 2, "bmw", "bus" }
   , seatsPassenger(10)
   , seatsTotal(20)
   , destination("Moscow")
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Bus::Bus(std::string make, std::string model, int seatsPassenger, int seatsTotal, std::string destination)
   : BaseVehicle{ 2, make, model}
   , seatsPassenger(seatsPassenger)
   , seatsTotal(seatsTotal)
   , destination(destination)
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Bus::Bus(const Bus& bus)
   : BaseVehicle{ 2, bus.make, bus.model}
   , seatsPassenger(bus.seatsPassenger)
   , seatsTotal(bus.seatsTotal)
   , destination(bus.destination)
{
   std::cout << "Class Motorcycle() created!" << std::endl;
}


Bus::~Bus()
{
   std::cout << "Class Motorcycle() deleted!" << std::endl;
}


std::string Bus::GetData() const
{
   return std::format("2\n{}\n{}\n{}\n{}\n{}", make, model, seatsPassenger, seatsTotal, destination);
}


void Bus::PrintData() const
{
   std::cout << "type: bus, model: " << make << ", model: " << model << ", seats passenger: "
      << seatsPassenger << ", seats total: " << seatsTotal << ", destination: " << destination << std::endl;;
}


void Bus::SetSeatsPassenger(int seatsPassenger_)
{
   seatsPassenger = seatsPassenger_;
}


void Bus::SetSeatsTotal(int seatsTotal_)
{
   seatsTotal = seatsTotal_;
}


void Bus::SetDestination(std::string destination_)
{
   destination = destination_;
}