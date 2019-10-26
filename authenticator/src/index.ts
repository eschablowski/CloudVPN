import express from "express";
import api from "./api";

const app = express();

api.then((router: express.Router) => {
    console.log(router)
    app.use("/api", router)
});

app.get("/", (req, res)=>{
    res.send("Hello");
})

app.listen("8080");