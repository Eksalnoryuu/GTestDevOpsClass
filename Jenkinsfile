pipeline {
    agent any
    stages 
    {
        stage('Build') 
        {
            steps 
            {
                script
                {
                    sh "docker build -t cont_build:latest -f /deploy/Dockerfile"
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    script
                    {
                        sh "docker container prune"
                        sh "docker volume prune"
                    }
                    emailext body: "The 'build' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
                }
            }
        }

        stage('Test') 
        {
            agent any
            steps 
            {
                script
                {
                    sh "docker build -t cont_test:latest -f /deploy/Dockerfile.second"
                }
            }
            post 
            {
                failure 
                {
                    script
                    {
                        sh "docker container prune"
                        sh "docker volume prune"
                    }
                    // send email notification on failure
                    emailext body: "The 'test' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
                }
            }
        }

        stage('Deploy') 
        {
            agent any
            steps 
            {
                script
                {
                    sh "docker build -t cont_deploy:1.0 -f /deploy/Dockerfile.third"
                }
            }
        }

        stage('Publish') {
            agent any
            steps 
            {
                archiveArtifacts artifacts: '*.tar', allowEmptyArchive: true
                sh "docker container prune"
                sh "docker volume prune"
            }
        }
    }
}
