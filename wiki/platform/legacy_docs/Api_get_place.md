h1. Api get place


Get Places for a location

endpoint: http://API_ROOT/v2/maps/getlocation?lat=LAT&lng=LNG&key=KEYWORD
method: POST


Example:

http://api.local.exfe.com/v2/maps/getlocation?lat=31.22&lng=121.48&key=apple

<pre>
venues: [
{
title: "Apple Store",
description: "淮海中路282号香港广场北座",
lng: 121.46980047226,
lat: 31.225077909646,
provider: "4sq",
external_id: "4cc248f5be40a35d7bb9704c",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Store",
description: "南京东路300号",
lng: 121.47720336914,
lat: 31.240985378021,
provider: "4sq",
external_id: "4e6ee88d1f6e63a4ea89e7d1",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Store",
description: "世纪大道8号IFC商场LG2-27号",
lng: 121.49692291188,
lat: 31.239334208309,
provider: "4sq",
external_id: "4c4d1eaee906c9280dde743b",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Garden | 苹果园",
description: "闸北区闻喜路",
lng: 121.4678177,
lat: 31.232168,
provider: "4sq",
external_id: "4c9a1b0ca004a1cdfd49456e",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Certifild",
description: null,
lng: 121.452483,
lat: 31.2145,
provider: "4sq",
external_id: "4f61a70ee4b063e59bd71925",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Service Center By Jack",
description: null,
lng: 121.452564,
lat: 31.214558,
provider: "4sq",
external_id: "4f9384afe4b01970bbf83e33",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Inc LABS",
description: null,
lng: 121.51705169678,
lat: 31.242733001709,
provider: "4sq",
external_id: "4f777a4de4b08f9be5a543ed",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "applebees",
description: null,
lng: 121.438602,
lat: 31.194558,
provider: "4sq",
external_id: "4b696815f964a5203ca12be3",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Fixer Guys",
description: "42 caoxibei lu, 23rd floor",
lng: 121.43489589915,
lat: 31.195768356564,
provider: "4sq",
external_id: "4cd670dc2944b1f7f11f63ec",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
},
{
title: "Apple Graden",
description: "昌里路",
lng: 121.49249,
lat: 31.173562,
provider: "4sq",
external_id: "4dc925bbae60385d11150a46",
created_at: null,
updated_at: null,
id: 0,
type: "Place"
}
],
meta: {
code: 200
}
}
</pre>



