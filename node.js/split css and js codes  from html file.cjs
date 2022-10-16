const fs = require('fs');
const path = require('path');

var cssContent, jsContent;

fs.readFile(path.join(__dirname, './index.html'), 'utf8', (err, data) => {
    if (!err) {
        cssContent = data.match(/(?<=<style>).*(?=<\/style>)/s)[0]; // 取出css内容
        jsContent = data.match(/(?<=<script>).*(?=<\/script>)/s)[0]; // 取出js内容
        
        fs.writeFile(path.join(__dirname,'./index.css'),cssContent,err=>{
            if(!err){
                console.log('css file has been split');
            }
        });
        fs.writeFile(path.join(__dirname,'./index.js'),jsContent,err=>{
            if(!err){
                console.log('js file has been split');
            }
        });
    }
})
