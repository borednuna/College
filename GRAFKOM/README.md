# DOKUMENTASI TASK 3 GRAFKOM WEBGL

```
Hanun Shaka Puspa
5025211051
Grafkom A
```

## RGB Square From 2 Triangles
Pada contoh kode yang diberikan, dilakukan konfigurasi titik-titik koordinat untuk setiap sudut segitiga, kemudian dikonfigurasi warna dari segitiga dan digambar dengan fungsi gl.drawArrays(gl.TRIANGLES, 0, 3); 

```
function draw() {
		gl.clearColor(0,0,0,1);  // specify the color to be used for clearing
    gl.clear(gl.COLOR_BUFFER_BIT);  // clear the canvas (to black)

    /* Set up values for the "coords" attribute */

    let  coords = new Float32Array( [ -0.5,-0.5, 0.5,-0.5, -0.5,0.5 ] );
   
    gl.bindBuffer(gl.ARRAY_BUFFER, bufferCoords);
    gl.bufferData(gl.ARRAY_BUFFER, coords, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeCoords, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeCoords); 
   
    /* Set up values for the "color" attribute */
   
    let  color = new Float32Array( [ 0,0,1, 0,1,0, 1,0,0 ] );

    gl.bindBuffer(gl.ARRAY_BUFFER, bufferColor);
    gl.bufferData(gl.ARRAY_BUFFER, color, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeColor, 3, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeColor); 
    
    /* Draw the triangle. */
   
    gl.drawArrays(gl.TRIANGLES, 0, 3);
}
```
Untuk menggambar satu lagi segitiga, dilakukan hal yang sama namun konfigurasi titik pada segitiga perlu disesuaikan sehingga fungsi draw() menjadi sebagai berikut :
```
function draw() { 

    gl.clearColor(0,0,0,1);  // specify the color to be used for clearing
    gl.clear(gl.COLOR_BUFFER_BIT);  // clear the canvas (to black)

    /* Set up values for the "coords" attribute */

    let  coords = new Float32Array( [ -0.5,-0.5, 0.5,-0.5, -0.5,0.5 ] );
   
    gl.bindBuffer(gl.ARRAY_BUFFER, bufferCoords);
    gl.bufferData(gl.ARRAY_BUFFER, coords, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeCoords, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeCoords); 
   
    /* Set up values for the "color" attribute */
   
    let  color = new Float32Array( [ 0,0,1, 0,1,0, 1,0,0 ] );

    gl.bindBuffer(gl.ARRAY_BUFFER, bufferColor);
    gl.bufferData(gl.ARRAY_BUFFER, color, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeColor, 3, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeColor); 
    
    /* Draw the triangle. */
   
    gl.drawArrays(gl.TRIANGLES, 0, 3);

    // Second triangle
    let  coords2 = new Float32Array( [ 0.5,0.5, 0.5,-0.5, -0.5,0.5 ] );

    gl.bindBuffer(gl.ARRAY_BUFFER, bufferCoords);
    gl.bufferData(gl.ARRAY_BUFFER, coords2, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeCoords, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeCoords);

    let  color2 = new Float32Array( [ 0,0,1, 0,1,0, 1,0,0 ] );

    gl.bindBuffer(gl.ARRAY_BUFFER, bufferColor);
    gl.bufferData(gl.ARRAY_BUFFER, color2, gl.STREAM_DRAW);
    gl.vertexAttribPointer(attributeColor, 3, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(attributeColor);

    gl.drawArrays(gl.TRIANGLES, 0, 3);

}
```

## Study Cube Program
Untuk mengubah tampilan kubus, dilakukan konfigurasi pada titik-titik koordinatnya
```
	drawPrimitive( gl.TRIANGLE_FAN, [0,1,0,1], 
			[ -0.5,-0.5,-0.5, -0.5,0.5,-0.5, 0.5,0.5,-0.5, 0.5,-0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,0,1],
			[ -0.5,-0.5,0.5, 0.5,-0.5,0.5, 0.5,0.5,0.5, -0.5,0.5,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,0,1,1],
			[ -0.5,0.5,-0.5, -0.5,0.5,0.5, 0.5,0.5,0.5, 0.5,0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,1,0,1],
			[ -0.5,-0.5,-0.5, 0.5,-0.5,-0.5, 0.5,-0.5,0.5, -0.5,-0.5,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,1,1],
			[ 0.5,-0.5,-0.5, 0.5,0.5,-0.5, 0.5,0.5,0.5, 0.5,-0.5,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,1,1,1],
			[ -0.5,-0.5,-0.5, -0.5,-0.5,0.5, -0.5,0.5,0.5, -0.5,0.5,-0.5 ]);
```
Untuk tampilan tampak depan-atas, dikonfigurasi menjadi seperti berikut
```
	 	drawPrimitive( gl.TRIANGLE_FAN, [0,1,0,1],
			[ -0.3,-0.5,-0.5, -0.3,0.3,-0.5, 0.5,0.3,-0.5, 0.5,-0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,0,1],
			[ -0.5,-0.3,0.5, 0.3,-0.3,0.5, 0.3,0.5,0.5, -0.5,0.5,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,0,1,1],
			[ -0.5,0.5,-0.5, -0.3,0.3,0.5, 0.3,0.3,0.5, 0.3,0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,1,0,1],
			[ -0.5,-0.3,-0.5, -0.3,-0.5,0.5, 0.5,-0.5,0.5, 0.3,-0.3,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,1,1],
			[ 0.5,-0.5,-0.5, 0.5,0.3,-0.5, 0.3,0.5,0.5, 0.3,-0.3,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,1,1,1],
			[ -0.5,-0.3,-0.5, -0.5,0.5,-0.5, -0.3,0.3,0.5, -0.3,-0.5,0.5 ]);
```
Tampak belakang :
```
	drawPrimitive( gl.TRIANGLE_FAN, [1,0,0,1],
			[ -0.3,-0.5,-0.5, -0.3,0.3,-0.5, 0.5,0.3,-0.5, 0.5,-0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,1,0,1],
			[ -0.5,-0.3,0.5, 0.3,-0.3,0.5, 0.3,0.5,0.5, -0.5,0.5,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,0,1,1],
			[ -0.5,0.5,-0.5, -0.3,0.3,0.5, 0.3,0.3,0.5, 0.3,0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,1,0,1],
			[ -0.5,-0.3,-0.5, -0.3,-0.5,0.5, 0.5,-0.5,0.5, 0.3,-0.3,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [0,1,1,1],
			[ 0.5,-0.5,-0.5, 0.5,0.3,-0.5, 0.3,0.5,0.5, 0.3,-0.3,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,1,1],
			[ -0.5,-0.3,-0.5, -0.5,0.5,-0.5, -0.3,0.3,0.5, -0.3,-0.5,0.5 ]);
```
Tampak kedua sisi samping :
```
	drawPrimitive( gl.TRIANGLE_FAN, [0,1,1,1], [ 0.5,-0.5,-0.5, 0.5,0.3,-0.5, 0.3,0.5,0.5, 0.3,-0.3,0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,0,1,1], [ -0.5,-0.3,-0.5, -0.5,0.5,-0.5, -0.3,0.3,0.5, -0.3,-0.5,0.5 ]);
```
Tampak sisi atas bawah :
```
	drawPrimitive( gl.TRIANGLE_FAN, [0,0,1,1], [ -0.5,0.5,-0.5, -0.3,0.3,0.5, 0.5,0.3,0.5, 0.3,0.5,-0.5 ]);
    drawPrimitive( gl.TRIANGLE_FAN, [1,1,0,1], [ -0.5,-0.3,-0.5, -0.3,-0.5,0.5, 0.5,-0.5,0.5, 0.3,-0.3,-0.5 ]);
```

Dokumentasi lengkap beserta gambar dapat dilihat di link [berikut](https://flying-pigs.notion.site/DOKUMENTASI-GRAFKOM-d174248589cd4ee18be006ff099d2542)
