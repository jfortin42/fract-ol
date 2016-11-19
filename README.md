# fract-ol

Fractol is a 42 Project designed to explore fractals.
<img align="center" src="http://image.noelshack.com/fichiers/2016/46/1479404257-fract-ol-mandelbrot.png" width="100%" />
Several options are available (see [Keyboard shortcuts](https://github.com/jfortin42/fract-ol#keyboard-shortcuts) and [Mouse controls](https://github.com/jfortin/fract-ol#mouse-controls) sections for more infos) :
* Zoom in and zoom out
* Change the number of iterations
* Navigate between the four fractals
* Edit the shape of the fractal with mouse motion (only available with the fractal Julia)

## Install & launch
```bash
git clone https://github.com/jfortin42/fract-ol ~/fract-ol
cd ~/fract-ol && make && ./fractol mandelbrot
```
Launch the program with one of the following parameters: mandelbrot, julia, burning or mandelbis.
Example :

Open the Julia fractal ⇣
```bash
./fractol julia
```
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Stop mouse motion (for Julia fractal only)</td>
<td valign="top" align="center"><kbd>&nbsp;Space&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase/decrease the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd> <kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reset the current fractal</td>
<td valign="top" align="center"><kbd>&nbsp;0&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change fractals</td>
<td valign="top" align="center"><kbd>&nbsp;1&nbsp;</kbd> <kbd>&nbsp;2&nbsp;</kbd> <kbd>&nbsp;3&nbsp;</kbd> <kbd>&nbsp;4&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;left button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;right button&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Contact & contribute
To contact me, or fix/improve Fractol, feel free to e-mail me at **jfortin@student.42.fr**
