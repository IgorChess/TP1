#include "lib.h"
#include <iostream>


int main()
{
   std::cout << "Commands:" << std::endl;
   std::cout << "1: get count vehicles in garage" << std::endl;
   std::cout << "2 [make] [model] [engineSize] [color] [gearboxType]: add car to garage" << std::endl;
   std::cout << "3 [make] [model] [engineSize] [enginePower] [motorcycleType]: add motorcycle to garage" << std::endl;
   std::cout << "4 [make] [model] [seatsPassenger] [seatsTotal] [destination]: add bus to garage" << std::endl;
   std::cout << "5 [index]: delete vehicle by index = [index] from garage" << std::endl;
   std::cout << "6 [filename]: save data from garage to file with name = [filename]" << std::endl;
   std::cout << "7 [filename]: load data from file with name = [filename] to garage" << std::endl;
   std::cout << "8 [index]: print vehicle data by index = [index] in garage" << std::endl;
   std::cout << "9 [index] [paramIndex] [newValue]: set newValue of value with index = [paramIndex] in vehicle in garage with index = [index]" << std::endl;
   std::cout << "10: quit from program" << std::endl;

   Garage* garage = new Garage();

   int command = 0;
   while (command != 10)
   {
	  std::cout << "Enter command: ";
	  std::cin >> command;
	  switch (command)
	  {
		 case 1:
		 {
			int countVehicles = garage->GetCountVehicles();
			std::cout << "vehicles count: " << countVehicles << std::endl;
			break;
		 }
		 case 2:
		 {
			std::string make, model, color, gearboxType;
			float engineSize;
			std::cin >> make >> model >> engineSize >> color >> gearboxType;
			BaseVehicle* car = new Car(make, model, engineSize, color, gearboxType);
			garage->Add(car);
			break;
		 }
		 case 3:
		 {
			std::string make, model, motorcycleType;
			float engineSize, enginePower;
			std::cin >> make >> model >> engineSize >> enginePower >> motorcycleType;
			BaseVehicle* motorcycle = new Motorcycle(make, model, engineSize, enginePower, motorcycleType);
			garage->Add(motorcycle);
			break;
		 }
		 case 4:
		 {
			std::string make, model, destination;
			int seatsPassenger, seatsTotal;
			std::cin >> make >> model >> seatsPassenger >> seatsTotal >> destination;
			BaseVehicle* bus = new Bus(make, model, seatsPassenger, seatsTotal, destination);
			garage->Add(bus);
			break;
		 }
		 case 5:
		 {
			int index;
			std::cin >> index;
			garage->Del(index);
			break;
		 }
		 case 6:
		 {
			std::string filename;
			std::cin >> filename;
			garage->Save(filename);
			break;
		 }
		 case 7:
		 {
			std::string filename;
			std::cin >> filename;
			garage->Load(filename);
			break;
		 }
		 case 8:
		 {
			int index;
			std::cin >> index;
			BaseVehicle* vehicle = garage->GetVehicle(index);
			vehicle->PrintData();
			break;
		 }
		 case 9:
		 {
			int index, paramIndex;
			std::string value;
			std::cin >> index >> paramIndex >> value;
			BaseVehicle* vehicle = garage->GetVehicle(index);
		
			switch (vehicle->type)
			{
			   case 0:
			   {
				  Car* car = (Car*)vehicle;
				  switch (paramIndex)
				  {
					 case 0: { car->SetMake(value); break; }
					 case 1: { car->SetModel(value); break; }
					 case 2: { car->SetEngineSize(std::stof(value)); break; }
					 case 3: { car->SetColor(value); break; }
					 case 4: { car->SetGearboxType(value); break; }
				  }
				  break;
			   }
			   case 1:
			   {
				  Motorcycle* motorcycle = (Motorcycle*)vehicle;
				  switch (paramIndex)
				  {
					 case 0: { motorcycle->SetMake(value); break; };
					 case 1: { motorcycle->SetModel(value); break; }
					 case 2: { motorcycle->SetEngineSize(std::stof(value)); break; }
					 case 3: { motorcycle->SetEnginePower(std::stof(value)); break; }
					 case 4: { motorcycle->SetMotorcycleType(value); break; }
				  }
				  break;
			   }
			   case 2:
			   {
				  Bus* bus = (Bus*)vehicle;
				  switch (paramIndex)
				  {
					 case 0: { bus->SetMake(value); break; }
					 case 1: { bus->SetModel(value); break; }
					 case 2: { bus->SetSeatsPassenger(std::stoi(value)); break; }
					 case 3: { bus->SetSeatsTotal(std::stoi(value)); break; }
					 case 4: { bus->SetDestination(value); break; }
				  }
				  break;
			   }
			}

			break;
		 }
	  }
   }

   return 0;
}