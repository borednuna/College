import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('aruco_tomo.csv')
df[:]

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

X, y = df[["pan", "tilt"]], df["dist"]

poly_reg_models = []
poly_reg_rmses = []
degrees = []
coefs = []

for i in range(1, 6):
  poly = PolynomialFeatures(degree=i)
  poly_features = poly.fit_transform(X)
  X_train, X_test, y_train, y_test = train_test_split(poly_features, y, test_size=0.3, random_state=42)

  poly_reg_model = LinearRegression()
  poly_reg_model.fit(X_train, y_train)

  poly_reg_y_predicted = poly_reg_model.predict(X_test)
  poly_reg_rmse = np.sqrt(mean_squared_error(y_test, poly_reg_y_predicted))

  poly_reg_models.append(poly_reg_model)
  poly_reg_rmses.append(poly_reg_rmse)
  degrees.append(i)
  coefs_ = []
  coefs_.append(poly_reg_model.intercept_)
  coefs_.append(poly_reg_model.coef_)
  coefs.append(coefs_)

plt.plot(degrees, poly_reg_rmses)
print(poly_reg_rmses)

best_model = poly_reg_models[np.argmin(poly_reg_rmses)]
best_degree = degrees[np.argmin(poly_reg_rmses)]
print(coefs[np.argmin(poly_reg_rmses)])
print(best_degree)

new_df = df[['pan', 'tilt']]
new_df['pan'] = 0
new_df = new_df.append({'pan': 0, 'tilt': -75}, ignore_index=True)
new_df = new_df.append({'pan': 0, 'tilt': -85}, ignore_index=True)
new_df = new_df.append({'pan': 0, 'tilt': -20}, ignore_index=True)
new_df = new_df.append({'pan': 0, 'tilt': -10}, ignore_index=True)
new_df = new_df.append({'pan': 0, 'tilt': -5}, ignore_index=True)
new_df = new_df.append({'pan': 11.5, 'tilt': -63.4}, ignore_index=True)
new_df = new_df.append({'pan': 6.4, 'tilt': -76.9}, ignore_index=True)
new_df = new_df.append({'pan': -1.1, 'tilt': -32.0}, ignore_index=True)
new_df = new_df.append({'pan': 1.6, 'tilt': -53.2}, ignore_index=True)



# new_df

# poly = PolynomialFeatures(degree=best_degree)
# poly_features = poly.fit_transform(new_df)

# new_df['dist'] = best_model.predict(poly_features)
# new_df

# poly.powers_