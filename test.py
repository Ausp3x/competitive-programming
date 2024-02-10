# import cartopy
# import cartopy.crs as crs
# import cartopy.feature as cf
# import matplotlib.pyplot as plt

# pC = crs.PlateCarree()
# pC._threshold = pC._threshold / 1000.  #set finer threshold
# ax = plt.axes(projection = pC)
# ax.add_feature(cf.LAND)
# ax.add_feature(cf.OCEAN)
# ax.add_feature(cf.BORDERS, linestyle = ':', linewidth = 5)
# ax.add_feature(cf.COASTLINE, linewidth = 5)
# ax.add_feature(cf.LAKES, alpha = 0.5)
# ax.add_feature(cf.RIVERS)

# ax.add_feature(cf.BORDERS)
# plt.plot([-151.98655, -148.89022, -146.64771, -144.82313, -143.25918, -141.87767, -140.63299, -139.49577, -138.44576, -137.46834, -136.55252, -135.68976, -134.87333, -134.09777, -133.35858, -132.65202, -131.97491, -131.32456, -130.69863, -130.0951, -129.51217, -128.94829, -128.40207, -127.87226, -127.35774, -126.85752, -126.37067, -125.89637, -125.43387, -124.98248, -124.54155, -124.1105, -123.68879, -123.27593, -122.87143, -122.47487, -122.08584, -121.70397, -121.32889, -120.96027, -120.5978, -120.24118, -119.89013, -119.54439, -119.20369, -118.86781, -118.53651, -118.20959, -117.88682, -117.56802, -117.253, -116.94157, -116.63356, -116.32881, -116.02715, -115.72843, -115.4325, -115.13922, -114.84845, -114.56004, -114.27389, -113.98984, -113.70779, -113.42761, -113.14919, -112.87241, -112.59716, -112.32333, -112.05082, -111.77953, -111.50935, -111.24017, -110.97192, -110.70447, -110.43775, -110.17166, -109.9061, -109.64099, -109.37623, -109.11173, -108.84741, -108.58317, -108.31894, -108.05461, -107.79011, -107.52535, -107.26025, -106.9947, -106.72864, -106.46198, -106.19462, -105.92649, -105.65749, -105.38754, -105.11655, -104.84444, -104.57111, -104.29648, -104.02045, -103.74294, -103.46385, -103.18309, -102.90057, -102.61618, -102.32984, -102.04145, -101.75091, -101.4581, -101.16295, -100.86532, -100.56513, -100.26226, -99.956603, -99.64804, -99.336459, -99.02174, -98.703763, -98.382403, -98.057532, -97.72902, -97.396734, -97.060536, -96.720284, -96.375834, -96.027035, -95.673733, -95.315771, -94.952984, -94.585204, -94.212256, -93.83396, -93.450129, -93.060572, -92.665089, -92.263473, -91.855509, -91.440974, -91.019639, -90.591262, -90.155593, -89.712373, -89.26133, -88.802181, -88.334632, -87.858374, -87.373086, -86.878429, -86.37405, -85.859579, -85.334627, -84.798784, -84.251621, -83.692685, -83.121496, -82.537552, -81.940317, -81.329226, -80.70368, -80.063041, -79.406632, -78.73373, -78.043563, -77.335304, -76.608069, -75.860904, -75.092784, -74.302599, -73.489149, -72.651128, -71.787114, -70.895549, -69.974723, -69.022748, -68.037535, -67.016755, -65.9578, -64.85773, -63.71321, -62.520426, -61.274977, -59.971737, -58.604668, -57.166563, -55.648694, -54.040298, -52.327823, -50.49377, -48.514808, -46.358568, -43.977698, -41.297678, -38.187786, -34.373119, -28.998209], 
#          [-6.6565557, -5.9493403, -5.3582475, -4.824607, -4.3271689, -3.8553328, -3.4028928, -2.9658391, -2.5414001, -2.1275629, -1.7228093, -1.32596, -0.93607646, -0.55239629, -0.17429006, 0.19876958, 0.56722995, 0.93147465, 1.2918357, 1.6486032, 2.0020321, 2.3523484, 2.6997534, 3.0444278, 3.3865339, 3.7262191, 4.0636172, 4.3988501, 4.7320297, 5.0632589, 5.3926324, 5.7202379, 6.0461567, 6.3704643, 6.6932313, 7.0145235, 7.3344025, 7.6529262, 7.970149, 8.2861221, 8.6008937, 8.9145095, 9.2270129, 9.5384447, 9.8488438, 10.158247, 10.46669, 10.774206, 11.080827, 11.386584, 11.691505, 11.995619, 12.298953, 12.601533, 12.903382, 13.204525, 13.504985, 13.804783, 14.10394, 14.402478, 14.700416, 14.997772, 15.294565, 15.590812, 15.886532, 16.181739, 16.476451, 16.770683, 17.064449, 17.357765, 17.650644, 17.9431, 18.235146, 18.526796, 18.818061, 19.108954, 19.399487, 19.689671, 19.979516, 20.269034, 20.558236, 20.847131, 21.135729, 21.42404, 21.712073, 21.999836, 22.28734, 22.574592, 22.8616, 23.148373, 23.434917, 23.721241, 24.007352, 24.293256, 24.57896, 24.864471, 25.149795, 25.434937, 25.719904, 26.004701, 26.289332, 26.573803, 26.858119, 27.142284, 27.426301, 27.710176, 27.99391, 28.277509, 28.560973, 28.844307, 29.127513, 29.410592, 29.693547, 29.976378, 30.259086, 30.541673, 30.824139, 31.106483, 31.388704, 31.670803, 31.952776, 32.234623, 32.516342, 32.797928, 33.079378, 33.36069, 33.641857, 33.922874, 34.203737, 34.484437, 34.764967, 35.04532, 35.325487, 35.605456, 35.885218, 36.164761, 36.444071, 36.723135, 37.001938, 37.280462, 37.558691, 37.836604, 38.11418, 38.391398, 38.668233, 38.944659, 39.220646, 39.496166, 39.771183, 40.045664, 40.31957, 40.59286, 40.865488, 41.137407, 41.408565, 41.678905, 41.948367, 42.216886, 42.484389, 42.750801, 43.016037, 43.280005, 43.542608, 43.803737, 44.063275, 44.321092, 44.577048, 44.830988, 45.08274, 45.332117, 45.578911, 45.822889, 46.063795, 46.30134, 46.535201, 46.765012, 46.990358, 47.210766, 47.425691, 47.634504, 47.836467, 48.030709, 48.216192, 48.391654, 48.555543, 48.705907, 48.840231, 48.955176, 49.046131, 49.106387, 49.125454, 49.085061, 48.947092, 48.593972], 
#          color = 'blue', linewidth = 20, transform = crs.Geodetic())

# plt.gcf().set_size_inches(100, 100)
# plt.savefig('Map.png', bbox_inches = 'tight')

# # https://stackoverflow.com/questions/60685245/plot-fine-grained-geodesic-with-cartopy/60724892#60724892
# # 

from mpmath import *
mp.dps = 100

l = [1, 2, 3, 4]
print(l[:3])