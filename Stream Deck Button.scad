module button(width = 10, r=3){

    hull(){
    translate([width,width,0])cylinder(h=5, r=r, $fn=60);
    translate([width,width,0])sphere(r=3, $fn=60);
    translate([-width,width,0])cylinder(h=5, r=r, $fn=60);
    translate([-width,width,0])sphere(r=3, $fn=60);
    translate([width,-width,0])cylinder(h=5, r=r, $fn=60);
    translate([width,-width,0])sphere(r=3, $fn=60);
    translate([-width,-width,0])cylinder(h=5, r=r, $fn=60);
    translate([-width,-width,0])sphere(r=3, $fn=60);
    }
}

button();