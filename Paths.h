#pragma once
#ifndef PATHS
#define PATHS

#include "projekt_zal.h"

// - Interfejsy do obs³ugi œcie¿ki
ID2D1PathGeometry* path_rocket_body = nullptr;
ID2D1PathGeometry* path_rocket_top = nullptr;
ID2D1PathGeometry* path_rocket_bottom = nullptr;
ID2D1PathGeometry* engines_rocket_path = nullptr;
ID2D1GeometrySink* path_sink_rocket_body = nullptr;
ID2D1GeometrySink* path_sink_rocket_top = nullptr;
ID2D1GeometrySink* path_sink_rocket_bottom = nullptr;
ID2D1GeometrySink* engines_rocket_path_sink = nullptr;
ID2D1PathGeometry* path_fire_t = nullptr;
ID2D1PathGeometry* path_fire_m = nullptr;
ID2D1PathGeometry* path_fire_b = nullptr;
ID2D1GeometrySink* path_sink_fire_t = nullptr;
ID2D1GeometrySink* path_sink_fire_m = nullptr;
ID2D1GeometrySink* path_sink_fire_b = nullptr;


#endif // !PATHS